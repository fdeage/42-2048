/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 14:37:37 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/23 14:14:34 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the 'all' option prints the 0s before the number:
** 5 will give 00000005 with all >  0
** 5 will give        5 with all == 0
*/

void	ft_printchar_hex_fd(unsigned char n, int fd, int *print_all)
{
	unsigned int	g;
	unsigned int	d;

	g = n / 16;
	d = n - (g * 16);
	if (g >= 10)
		ft_putchar_fd(g + 87, fd);
	else if (*print_all == 1 || g > 0)
		ft_putchar_fd(g + '0', fd);
	*print_all = 1;
	if (d >= 10)
		ft_putchar_fd(d + 87, fd);
	else
		ft_putchar_fd(d + '0', fd);
}

void	ft_printhex_fd(uint32_t n, int fd, int print_all)
{
	if ((n / (256 * 256 * 256)) || print_all)
		ft_printchar_hex_fd((n / (256 * 256 * 256)), fd, &print_all);
	n -= (256 * 256 * 256) * (n / (256 * 256 * 256));
	if ((n / (256 * 256)) || print_all)
		ft_printchar_hex_fd((n / (256 * 256)), fd, &print_all);
	n -= (256 * 256) * (n / (256 * 256));
	if ((n / 256) || print_all)
		ft_printchar_hex_fd((n / 256), fd, &print_all);
	n -= (256) * (n / (256));
	ft_printchar_hex_fd(n, fd, &print_all);
}

void	ft_printhex(uint32_t n, int print_all)
{
	ft_printhex_fd(n, 1, print_all);
	return ;
}
