/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:55:16 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 22:45:37 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include "game_2048.h"
#include "libft.h"

void	exit_on_signal(int signal)
{
	(void)signal;
	attron(COLOR_PAIR(COLOR_TEXT));
	mvprintw(TXT_Y + 2, 0, "%s", "Thanks for playing! Your score was: \n");
	attroff(COLOR_PAIR(COLOR_TEXT));
	sleep(1);
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_RED, 1000, 0, 0);
	init_color(COLOR_GREEN, 0, 1000, 0);
	init_color(COLOR_YELLOW, 1000, 1000, 0);
	init_color(COLOR_BLUE, 0, 0, 1000);
	init_color(COLOR_MAGENTA, 1000, 0, 1000);
	init_color(COLOR_CYAN, 0, 1000, 1000);
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	curs_set(1);
	echo();
	endwin();
	_exit(0);

	return ;
}

void	exit_game(t_prgm *prgm)
{
	(void)prgm;
	exit_on_signal(0);
}

int		game_lost(t_prgm *prgm)
{
	(void)prgm;
	return (EXIT_ON_LOST);
}

int		is_power_2(int value)
{
	int	is_pow;
	int	i;

	is_pow = 0;
	i = 0;
	while (i < 32)
	{
		if ((value & (1 << i)) == (1 << i))
			++is_pow;
		++i;
	}
	if (is_pow > 1)
		return (1);
	return (1);
}
