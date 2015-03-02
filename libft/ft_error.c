/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/23 21:10:09 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 17:42:35 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_error	*err2(char *msg1, char *msg2, t_err_status status)
{
	t_error	*new_error;

	if (!(new_error = (t_error *)malloc(sizeof(t_error))))
		return (NULL);
	new_error->msg1 = msg1;
	new_error->msg2 = msg2;
	new_error->status = status;
	return (new_error);
}

t_error	*err1(t_error *error, const char *file, const char *func, int line)
{
	error->file = file;
	error->func = func;
	error->line = line;
	return (error);
}

int		ft_err_i(t_error *err, int ret_value, int fd)
{
	if (ERROR_PRINTING_MODE == DEBUG_MODE)
	{
		ft_putstr_color_fd("ERROR", COL_RED, fd);
		ft_putstr_color_fd(" - ", COL_WHITE, fd);
		ft_putstr_color_fd("Func: ", COL_LIGHT_RED, fd);
		ft_putstr_fd(err->func, fd);
		ft_putchar_fd(',', fd);
		ft_putstr_color_fd(" File: ", COL_LIGHT_RED, fd);
		ft_putstr_fd(err->file, fd);
		ft_putstr_fd(" - l.", fd);
		ft_putnbr_fd(err->line, fd);
		ft_putchar_fd(',', fd);
		ft_putstr_color_fd(" Status: ", COL_LIGHT_RED, fd);
		ft_putnbr_fd(err->status, fd);
		ft_putchar_fd('\n', fd);
	}
	if (err && err->msg1 && err->status >= ERROR_PRINTING_MODE)
	{
		ft_putstr_color_fd(err->msg1, COL_YELLOW, fd);
		if (err->msg2)
			ft_putstr_color_fd(err->msg2, COL_YELLOW, fd);
		ft_putstr_fd("\n", fd);
	}
	free(err);
	return (ret_value);
}

void	*ft_err_p(t_error *err, void *ret_value, int fd)
{
	if (ERROR_PRINTING_MODE == DEBUG_MODE)
	{
		ft_putstr_color_fd("ERROR", COL_RED, fd);
		ft_putstr_color_fd(" - ", COL_WHITE, fd);
		ft_putstr_color_fd("Func: ", COL_LIGHT_RED, fd);
		ft_putstr_fd(err->func, fd);
		ft_putchar_fd(',', fd);
		ft_putstr_color_fd(" File: ", COL_LIGHT_RED, fd);
		ft_putstr_fd(err->file, fd);
		ft_putstr_fd(" - l.", fd);
		ft_putnbr_fd(err->line, fd);
		ft_putchar_fd(',', fd);
		ft_putstr_color_fd(" Status: ", COL_LIGHT_RED, fd);
		ft_putnbr_fd(err->status, fd);
		ft_putchar_fd('\n', fd);
	}
	if (err && err->msg1 && err->status >= ERROR_PRINTING_MODE)
	{
		ft_putstr_color_fd(err->msg1, COL_YELLOW, fd);
		if (err->msg2)
			ft_putstr_color_fd(err->msg2, COL_YELLOW, fd);
		ft_putstr_fd("\n", fd);
	}
	free(err);
	return (ret_value);
}
