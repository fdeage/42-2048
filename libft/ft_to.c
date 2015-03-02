/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 09:45:03 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/21 15:29:21 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	if (c == (int)' ' || c == (int)'\t' || c == (int)'\n'
		|| c == (int)'\v' || c == (int)'\f' || c == (int)'\r')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (c >= (int)'A' && c <= (int)'Z')
		return (c + 32);
	return (c);
}

int	ft_toupper(int c)
{
	if (c >= (int)'a' && c <= (int)'z')
		return (c - 32);
	return (c);
}
