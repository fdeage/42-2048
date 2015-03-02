/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:32:42 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/27 14:39:30 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_min(size_t a, size_t b)
{
	return (a < b ? a : b);
}

size_t	ft_max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

float	ft_min_float(float a, float b)
{
	return (a < b ? a : b);
}

float	ft_max_float(float a, float b)
{
	return (a > b ? a : b);
}
