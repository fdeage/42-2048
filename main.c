/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:16:53 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 23:44:29 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <ncurses.h>
#include <unistd.h>
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
		return (ERR_NO_COLOR);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_BACK);
	init_pair(2, COLOR_F_2, COLOR_B_2);
	init_pair(4, COLOR_F_4, COLOR_B_4);
	init_pair(8, COLOR_F_8, COLOR_B_8);
	init_pair(16, COLOR_F_16, COLOR_B_16);
	init_pair(32, COLOR_F_32, COLOR_B_32);
	init_pair(64, COLOR_F_64, COLOR_B_64);
	init_pair(128, COLOR_F_128, COLOR_B_128);
	init_pair(129, COLOR_F_256, COLOR_B_256);
	init_pair(130, COLOR_F_512, COLOR_B_512);
	init_pair(131, COLOR_F_1024, COLOR_B_1024);
	init_pair(132, COLOR_F_2048, COLOR_B_2048);
	init_pair(133, COLOR_F_4096, COLOR_B_4096);
	init_pair(134, COLOR_F_0, COLOR_B_0);
	init_pair(135, COLOR_BLACK, COLOR_BACK);
	init_pair(COLOR_TEXT, COLOR_WHITE, COLOR_BLACK);
	return (RET_OK);
}

static void	init_grid(t_prgm *prgm, int it)
{
	int	i;
	int	j;
	int	new1;
	int	new2;

	new1 = rand() % (prgm->n * prgm->n);
	new2 = -1;
	while (new2 == -1 || new2 == new1)
		new2 = rand() % (prgm->n * prgm->n);
	i = 0;
	while (i < prgm->n)
	{
		j = 0;
		while (j < prgm->n)
		{
			(prgm->grid[i][j]).value = 0;
			if (it == new1 || it == new2)
				(prgm->grid[i][j]).value = ((rand() % 4 == 0) ? 4 : 2);
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
	prgm->win = NULL;
	if (init_ncurses_screen(prgm) == ERR_INIT_FAILED)
		exit_game(prgm);
	if (!is_power_2(WIN_VALUE))
	{
		wattron(prgm->win, COLOR_PAIR(COLOR_TEXT));
		mvwprintw(prgm->win, 0, 0, "%s",
			"The winning condition isn't 2^x.\n");
		wattroff(prgm->win, COLOR_PAIR(COLOR_TEXT));
		exit_game(prgm);
	}
	//prgm->width = 0;
	//prgm->height = 0;
	prgm->cont = 0;
	prgm->clr_pair = -1;
	prgm->highest = 0;
	prgm->begin_time = time(NULL);
	prgm->score = 0;
	reinit_colors();
	return (RET_OK);
}

int			main(int ac, char *av[])
{
	t_prgm	prgm;
	int		ret;

	(void)ac;
	(void)av;
	prgm.n = SQUARE_RANGE;
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
