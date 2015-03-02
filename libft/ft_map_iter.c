/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_iter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 14:03:19 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/13 17:42:06 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** ft_striter applies the f function to every char in the string s.
** striter gives the index of the char as well.
** ft_strmap applies  the f function to every char in the string s, and creates
** a new string with malloc.
** strmapi gives the index of the char as well.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	register size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
		f(&s[i++]);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		++i;
	}
}

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*new;
	register size_t	i;
	size_t			len_s;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	if (!(new = (char *)malloc((len_s + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(s[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;
	size_t			len_s;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	if (!(new = (char *)malloc((len_s + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}
