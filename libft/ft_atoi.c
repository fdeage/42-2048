/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/08 14:05:35 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/21 10:32:40 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	int	res;
	int	i;
	int	sign;

	res = 0;
	sign = 1;
	i = 0;
	while (s[i] && ft_isspace(s[i]))
		++i;
	if (s[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (s[i] == '+')
		++i;
	while (s[i] && ft_isdigit(s[i]) && !ft_isspace(s[i]))
		res = res * 10 + s[i++] - '0';
	return (sign * res);
}
