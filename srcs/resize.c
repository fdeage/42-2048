/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 00:04:38 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/03 00:20:15 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game_2048.h"

# include<unistd.h>

# include<string.h>
# include<signal.h>
# include<sys/ioctl.h>


void	resize_screen(int input)
{
	int	y;
	int	x;

	return ;
	x = 0;
	y = 0;
	//getmaxyx(win, y, x);
	//if (is_term_resized(lines, int columns);
	(void)input;

	struct winsize	w;

	ioctl(0, TIOCGWINSZ, &w);
	COLS = w.ws_col;
	LINES = w.ws_row;
	wresize(stdscr, LINES, COLS);
	clear();
	mvprintw(0, 0, "COLS = %d, LINES = %d", COLS, LINES);
	sleep(1);
	//int i;
	//for (i = 0; i < COLS; i++)
	//	mvaddch(1, i, '*');
	refresh();
	return ;
}
