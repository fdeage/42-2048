/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 16:38:27 by fdeage            #+#    #+#             */
/*   Updated: 2014/05/13 15:13:31 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/*
** returns a long int a ^ b
** ft_realloc uses a dedicated pow2 function with bit-shifting
*/

size_t	pow_a(int a, unsigned int b)
{
	size_t	ret;

	ret = 1;
	while (b)
	{
		ret *= (size_t)a;
		--b;
	}
	return (ret);
}
