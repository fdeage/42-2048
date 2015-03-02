/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 14:17:08 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/28 14:56:18 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void	join_buf(t_buf *buf)
{
	char	*tmp;

	if (!(buf->is_init))
	{
		if (!(buf->rem = (char *)ft_memalloc(sizeof(char) * MALLOC_SIZE)))
			return ;
		buf->malloc_size = MALLOC_SIZE;
		buf->is_init = 1;
	}
	while (buf->buf_len + buf->rem_len >= buf->malloc_size)
	{
		tmp = buf->rem;
		if (!(buf->rem = (char *)malloc(sizeof(char) * buf->malloc_size * 2)))
			return ;
		ft_strncpy(buf->rem, tmp, buf->rem_len + 1);
		buf->rem[buf->rem_len] = 0;
		buf->malloc_size *= 2;
		free(tmp);
	}
	buf->rem_len += buf->buf_len;
	ft_strncat(buf->rem, buf->buf, buf->buf_len);
	buf->buf[0] = '\0';
	buf->buf_len = 0;
}

static int	search_newline(t_buf *buf, char **line)
{
	*line = NULL;
	while (buf->search_index < buf->rem_len && buf->rem[buf->search_index])
	{
		if (buf->rem[buf->search_index] == 0x0a)
		{
			if (!(*line = (char *)malloc(sizeof(char) *
				(buf->search_index + 1))))
				return (false);
			ft_strncpy(*line, buf->rem, buf->search_index);
			(*line)[buf->search_index] = '\0';
			ft_strcpy(buf->rem, buf->rem + buf->search_index + 1);
			buf->rem_len -= (buf->search_index + 1);
			buf->search_index = 0;
			return (true);
		}
		++(buf->search_index);
	}
	return (false);
}

static int	leave(int ret, t_buf *buf, char **line)
{
	if (ret == -1)
		return (ret);
	if (buf->is_init == 1)
	{
		*line = ft_strdup(buf->rem);
		free(buf->rem);
		buf->rem = NULL;
		buf->rem_len = 0;
		buf->malloc_size = 0;
		buf->search_index = 0;
		buf->is_init = 0;
	}
	else
	{
		if (!(*line = (char *)malloc(sizeof(char) * 1)))
			return (-1);
		(*line)[0] = 0;
	}
	return (ret);
}

static int	handle_fd(int fd, t_buf **bufs)
{
	if (!(bufs[fd]))
	{
		if (!(bufs[fd] = (t_buf *)malloc(sizeof(t_buf))))
			return (-1);
		ft_bzero((bufs[fd])->buf, BUF_SIZE + 1);
		(bufs[fd])->buf_len = 0;
		(bufs[fd])->rem = 0;
		(bufs[fd])->rem_len = 0;
		(bufs[fd])->malloc_size = 0;
		(bufs[fd])->search_index = 0;
		(bufs[fd])->is_init = 0;
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	int				ret;
	static t_buf	*bufs[MAX_FD] = {0};

	if (fd < 0 || !line || BUF_SIZE < 1 || fd >= MAX_FD)
		return (-1);
	if (handle_fd(fd, (t_buf **)&bufs) == -1)
		return (-1);
	if (search_newline(bufs[fd], line))
		return (1);
	while ((ret = read(fd, (bufs[fd])->buf, BUF_SIZE)) > 0)
	{
		(bufs[fd])->buf[ret] = '\0';
		(bufs[fd])->buf_len = ft_strlen((bufs[fd])->buf);
		join_buf(bufs[fd]);
		if (search_newline(bufs[fd], line))
			return (1);
	}
	return (leave(ret, (bufs)[fd], line));
}
