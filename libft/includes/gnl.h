/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 11:46:04 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 17:44:08 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

/*
** ft_gnl: handles multiple fd at the same time
** 1024 seems to be the best trade-off nb of read/buffer size (BUF_SIZE)
*/

# define BUF_SIZE			1024
# define MALLOC_SIZE		65536
# define MAX_FD				512

typedef struct s_buf		t_buf;

struct		s_buf
{
	char			buf[BUF_SIZE + 1];
	size_t			buf_len;
	char			*rem;
	size_t			rem_len;
	size_t			malloc_size;
	size_t			search_index;
	char			is_init;
};

int			get_next_line(int fd, char **line);

#endif
