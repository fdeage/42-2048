/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:26:14 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 21:26:57 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"


#include <stdio.h>

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
			//mvprintw(TXT_Y + 2, 1, "[%d %d] = %d", i, j, (grid[i][j]).value);

			//mvprintw(TXT_Y + 1, 1, "%d", i);
			//mvprintw(TXT_Y + 1, 4, "%d", j);
			//mvprintw(TXT_Y + 1, 7, "%d", (grid[i][j]).value);
			//fprintf(stderr, "[%d, %d] = %d\n", i, j, (grid[i][j]).value);
			if ((grid[i][j]).value == 0)
			{
				++free;
			}
			++j;
		}
		++i;
	}
	//mvprintw(TXT_Y + 2, 1, "free = %d", free);
	//fprintf(stderr, "size = %d\n", free);
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
					(prgm->grid[prgm->i][j]).value = (rand() % 4 == 0 ? 4 : 2);
					return (RET_OK);
				}
			}
		}
	}
	return (RET_OK);
}
