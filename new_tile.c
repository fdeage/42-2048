/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:26:14 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:10:46 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	count_free_tiles(t_tile grid[SQUARE_RANGE][SQUARE_RANGE])
{
	int	free;
	int	i;
	int	j;

	free = 0;
	i = 0;
	while (i < SQUARE_RANGE)
	{
		j = 0;
		while (j < SQUARE_RANGE)
		{
			if ((grid[i][j]).value == 0)
				++free;
			++j;
		}
		++i;
	}
	return (free);
}

int			create_new_tile(t_prgm *prgm)
{
	int	free;
	int	j;
	int	new;

	if (!(free = count_free_tiles(prgm->grid)))
		return (ERR_SQUARE_FULL);
	new = rand() % free + 1;
	free = 0;
	prgm->i = -1;
	while (++(prgm->i) < SQUARE_RANGE)
	{
		j = -1;
		while (++j < SQUARE_RANGE)
		{
			if ((prgm->grid[prgm->i][j]).value == 0)
			{
				if (++free == new)
				{
					(prgm->grid[prgm->i][j]).value = (rand() % 3 == 0 ? 4 : 2);
					return (RET_OK);
				}
			}
		}
	}
	return (RET_OK);
}
