/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:16:53 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 17:45:21 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <ncurses.h>
#include "game_2048.h"

static void	handle_signals(int s)
{
	(void)s;
	signal(SIGINT, exit_on_signal);
}

static int	init_ncurses_screen(t_prgm *prgm)
{
	if (!(prgm->win = initscr()))
		return (ERR_INITSCR);
	noecho();
	curs_set(0);
	keypad(prgm->win, TRUE);
	if (!has_colors() || !can_change_color())
	{
		fprintf(stderr, "Your life sucks.\n");
		return (ERR_NO_COLOR);
	}
	else
		start_color();
	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_2);
	init_pair(4, COLOR_RED, COLOR_4);
	init_pair(8, COLOR_RED, COLOR_8);
	init_pair(16, COLOR_RED, COLOR_16);
	init_pair(32, COLOR_BLUE, COLOR_32);
	init_pair(64, COLOR_RED, COLOR_64);
	init_pair(65, COLOR_WHITE, COLOR_ELSE);
	fprintf(stderr, "nbcol = %d nbcolopair = %d\n", COLORS, COLOR_PAIRS);
	return (RET_OK);
}

static void	init_grid(t_prgm *prgm, int it)
{
	int	i;
	int	j;
	int	new1;
	int	new2;

	new1 = rand() % (SQUARE_RANGE * SQUARE_RANGE);
	new2 = -1;
	while (new2 == -1 || new2 == new1)
		new2 = rand() % (SQUARE_RANGE * SQUARE_RANGE);
	i = 0;
	while (i < SQUARE_RANGE)
	{
		j = 0;
		while (j < SQUARE_RANGE)
		{
			(prgm->grid[i][j]).value = 0;
			if (it == new1 || it == new2)
				(prgm->grid[i][j]).value = ((rand() % 2 == 0) ? 2 : 4);
			++it;
			++j;
		}
		++i;
	}
}

static int	init_game(t_prgm *prgm)
{
	srand(time(NULL));
	init_grid(prgm, 0);
	if (!is_power_2(WIN_VALUE))
	{
		ft_putstr_color("The winning condition isn't 2^x.\n", COL_RED);
		exit_game(prgm);
	}
	prgm->win = NULL;
	if (init_ncurses_screen(prgm) == ERR_INIT_FAILED)
		exit_game(prgm);
	//prgm->width = 0;
	//prgm->height = 0;
	prgm->cont = 0;
	prgm->clr_pair = -1;
	//prgm->back_clr = COLOR_BLACK;
	//prgm->highest = 0;
	prgm->begin_time = time(NULL);
	prgm->score = 0;
	reinit_color();
	return (RET_OK);
}

int			main(void)
{
	t_prgm	prgm;
	int		ret;

	if (init_game(&prgm) != RET_OK)
	{
		ft_putstr_color("Init failed.\n", COL_RED);
		return (EXIT_FAILURE);
	}
	display_grid(&prgm);
	handle_signals(0);
	ret = CONTINUE_GAME;
	while (ret == CONTINUE_GAME)
		ret = run_2048(&prgm);
	exit_game(&prgm);
	return (EXIT_SUCCESS);
}
