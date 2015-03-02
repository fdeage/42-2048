/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:11:38 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:40:02 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "game_2048.h"
#include "libft.h"

static void	print_char
	(t_prgm *prgm, char ch, int x, int y)
{
	init_pair(1, COLOR_RED, COLOR_WHITE);
	wattron(prgm->win, COLOR_PAIR(1));
	mvwaddch(prgm->win, x, y, ch);
	wattroff(prgm->win, COLOR_PAIR(1));
}

static void	print_nbr
	(t_prgm *prgm, int nbr, int y, int x)
{
	char	tab[12];

	ft_itoatab(nbr, tab);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	wattron(prgm->win, COLOR_PAIR(1));
	mvwprintw(prgm->win, y, x, "%s", tab);
	wattroff(prgm->win, COLOR_PAIR(1));
}

static void	print_tile(t_prgm *prgm, int x, int y)
{
	int	i;
	int	j;

	prgm->back_clr = get_tile_color((prgm->grid[x][y]).value);
	i = 0;
	while (i < SQUARE_SIZE_X)
	{
		j = 0;
		while (j < SQUARE_SIZE_Y)
		{
			if (i == 0 || i == SQUARE_SIZE_X - 1 || j == 0
				|| j == SQUARE_SIZE_Y - 1)
				print_char(prgm, ' ', ((SQUARE_SIZE_X + 1) * x) + i + 1,
				((SQUARE_SIZE_Y + 1) * y) + j + 1);
			if (i == SQUARE_SIZE_X / 2 && j == SQUARE_SIZE_Y / 2
				&& (prgm->grid[x][y]).value > 0)
			{
				print_nbr(prgm, (prgm->grid[x][y]).value,
					((SQUARE_SIZE_X + 1) * x) + i + 1,
					((SQUARE_SIZE_Y + 1) * y) + j + 1);
			}
			++j;
		}
		++i;
	}
}

static void	display_frame(t_prgm *prgm, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < SQUARE_SIZE_X)
	{
		j = 0;
		while (j < SQUARE_SIZE_Y)
		{
			print_char(prgm, ' ', ((SQUARE_SIZE_X + 1) * x) + i + 1,
				((SQUARE_SIZE_Y + 1) * y) + j + 1);
			++j;
		}
		++i;
	}
}

int			display_grid(t_prgm *prgm)
{
	int		x;
	int		y;

	x = 0;
	while (x < SQUARE_RANGE)
	{
		y = 0;
		while (y < SQUARE_RANGE)
		{
			display_frame(prgm, x, y);
			print_tile(prgm, x, y);
			++y;
		}
		++x;
	}
	wrefresh(prgm->win);
	return (RET_OK);
}
