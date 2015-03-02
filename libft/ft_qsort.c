/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/16 15:51:40 by fdeage            #+#    #+#             */
/*   Updated: 2015/01/22 19:54:39 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** implementation of a quicksort, pivot is always chosen as the middle number
*/

static void	swap(int tab[], int a, int b)
{
	int	tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

void		ft_qsort(int tab[], int beg, int end)
{
	int			left;
	int			right;
	const int	pivot = tab[(end - beg) / 2];

	left = beg - 1;
	right = end + 1;
	if (beg >= end)
		return ;
	while (1)
	{
		while (tab[right] > pivot)
			--right;
		while (tab[left] < pivot)
			++left;
		if (left < right)
			swap(tab, left, right);
		else
			break ;
	}
	ft_qsort(tab, beg, right);
	ft_qsort(tab, right + 1, end);
}
