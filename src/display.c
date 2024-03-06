/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 17:11:38 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 23:57:18 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include "game_2048.h"
#include "libft.h"

static void	print_char
	(t_prgm *prgm, char ch, int x, int y)
{
	wattron(prgm->win, COLOR_PAIR(prgm->clr_pair));
	mvwaddch(prgm->win, x, y, ch);
	wattroff(prgm->win, COLOR_PAIR(prgm->clr_pair));
}

static void	print_nbr
	(t_prgm *prgm, int nbr, int y, int x)
{
	wattron(prgm->win, COLOR_PAIR(prgm->clr_pair));
	mvwprintw(prgm->win, y, x, "%d", nbr);
	wattroff(prgm->win, COLOR_PAIR(1));
}

static void	print_tile(t_prgm *prgm, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < prgm->width)
	{
		j = 0;
		while (j < prgm->height)
		{
			if (i == 0 || i == prgm->width - 1 || j == 0
				|| j == prgm->height - 1)
				print_char(prgm, ' ', ((prgm->width + 1) * x) + i + 1,
				((prgm->height + 2) * y) + j + 1);
			if (i == ((prgm->width + 1) / 2 - 1) && j ==
				((prgm->height + 1) / 2 - 1) && (prgm->grid[x][y]).value > 0)
			{
				print_nbr(prgm, (prgm->grid[x][y]).value,
					((prgm->width + 1) * x) + i + 1,
					((prgm->height + 2) * y) + j + 1);
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
	while (i < prgm->width)
	{
		j = 0;
		while (j < prgm->height)
		{
			print_char(prgm, ' ', ((prgm->width + 1) * x) + i + 1,
				((prgm->height + 2) * y) + j + 1);
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
	while (x < prgm->n)
	{
		y = 0;
		while (y < prgm->n)
		{
			prgm->clr_pair = get_tile_color((prgm->grid[x][y]).value);
			display_frame(prgm, x, y);
			print_tile(prgm, x, y);
			++y;
		}
		++x;
	}
	wrefresh(prgm->win);
	return (RET_OK);
}
