/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:38:28 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 23:53:01 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ncurses.h>
#include "game_2048.h"
#include "libft.h"

static int	get_score(t_tile grid[SQUARE_RANGE][SQUARE_RANGE], int n)
{
	int	x;
	int	y;
	int	highest;

	x = 0;
	highest = 0;
	while (x < n)
	{
		y = 0;
		while (y < n)
		{
			if ((grid[x][y]).value > highest)
				highest = (grid[x][y]).value;
			++y;
		}
		++x;
	}
	return (highest);
}

static void	display_score(WINDOW *win, int score, int x, int y)
{
	mvwprintw(win, y / 2, x, "%s", "Score: ");
	mvwprintw(win, y / 2, x + 8, "%d", score);
}

static int	handle_input(t_prgm *prgm, int input)
{
	if (input == KEY_RIGHT || input == KEY_LEFT || input == KEY_UP
		|| input == KEY_DOWN)
	{
		compute_new_state(prgm, input, 0);
		return (KEY_ARROWS);
	}
	else if (input == KEY_ESC)
		exit_game(prgm);
	return (NO_MOVE);
}

static int	prompt_continue(t_prgm *prgm)
{
	int	ret;
	int	ch;

	mvwprintw(prgm->win, TXT_Y, 1, "%s", "You reached ");
	mvwprintw(prgm->win, TXT_Y, 13, "%d", prgm->score);
	mvwprintw(prgm->win, TXT_Y, 16, "%s", "! Continue ? [y/n]\n");
	echo();
	ret = 1;
	while (ret == 1)
	{
		ch = getch();
		if (ch == 'Y' || ch == 'y')
		{
			prgm->cont = 1;
			noecho();
			mvwprintw(prgm->win, TXT_Y, 0, "%s",
				"     INFINITE MODE                     ");
			mvwprintw(prgm->win, TXT_Y + 1, 0, "%s", "  ");
			ret = 0;
			return (CONTINUE_GAME);
		}
		else if (ch == 'N' || ch == 'n')
			return (LEAVE_GAME);
	}
	return (RET_OK);
}

int			run_2048(t_prgm *prgm)
{
	int		input;

	while (prgm->score < WIN_VALUE || prgm->cont)
	{
		input = getch();
		if (redim_screen(input) == REDIM_SIGNAL)
			display_grid(prgm);
		if (handle_input(prgm, input) == KEY_ARROWS
			&& ft_memcmp(prgm->new, prgm->grid, sizeof(prgm->grid)) != 0)
		{
			ft_memcpy(prgm->grid, prgm->new, sizeof(prgm->grid));
			ft_bzero(prgm->new, sizeof(prgm->grid));
			prgm->score = get_score(prgm->grid, prgm->n);
			prgm->highest = ft_max(prgm->highest, prgm->score);
			if (create_new_tile(prgm) == ERR_SQUARE_FULL)
			{
				sleep(1);
				if (game_lost(prgm) == EXIT_ON_LOST)
					exit_game(prgm);
			}
			display_grid(prgm);
			display_score(prgm->win, prgm->score, TXT_X, TXT_Y);
		}
	}
	return (prompt_continue(prgm));
}
