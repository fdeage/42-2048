/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:55:16 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:24:36 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include "game_2048.h"
#include "libft.h"

void	exit_on_signal(int signal)
{
	(void)signal;
	ft_putstr_color("Thanks for playing! Your score was: \n", COL_GREEN);
	curs_set(1);
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

	return (1);
	is_pow = 0;
	i = 0;
	while (i < 32)
	{
		if ((value & 1 << i) == 1)
		{
			if (is_pow == 1)
				return (0);
			is_pow = 1;
		}
		++i;
	}
	return (1);
}
