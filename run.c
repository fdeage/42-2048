/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:38:28 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 17:36:24 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ncurses.h>
#include "game_2048.h"
#include "libft.h"

static int	get_score(t_tile grid[SQUARE_RANGE][SQUARE_RANGE])
{
	int	x;
	int	y;
	int	highest;

	x = 0;
	highest = 0;
	while (x < SQUARE_RANGE)
	{
		y = 0;
		while (y < SQUARE_RANGE)
		{
			if ((grid[x][y]).value > highest)
				highest = (grid[x][y]).value;
			++y;
		}
		++x;
	}
	return (highest);
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
	char	buf[12];
	int		ret;

	(void)prgm;
	ft_bzero(buf, 16);
	ft_putstr_color("You reached ", COL_LIGHT_GREEN);
	ft_itoatab(prgm->score, buf);
	ft_putstr_color(buf, COL_GREEN);
	ft_putstr_color("! Continue ? [Y/N]\n", COL_LIGHT_GREEN);
	ret = 1;
	while ((ret = read(0, &buf, 1)) == 1)
	{
		ret = 0;
		if (ft_strcmp("Y", buf))
		{
			prgm->cont = 1;
			return (CONTINUE_GAME);
		}
		else if (ft_strcmp("N", buf))
			return (LEAVE_GAME);
		else
			ret = 1;
	}
	return (RET_OK);
}

int			run_2048(t_prgm *prgm)
{
	int		input;

	while (prgm->highest < WIN_VALUE || prgm->cont)
	{
		input = getch();
		if (redim_screen(input) == REDIM_SIGNAL)
			display_grid(prgm);
		if (handle_input(prgm, input) == KEY_ARROWS
			&& ft_memcmp(prgm->new, prgm->grid, sizeof(prgm->grid)) != 0)
		{
			prgm->score = get_score(prgm->grid);
			prgm->highest = ft_max(prgm->highest, prgm->score);
			ft_memcpy(prgm->grid, prgm->new, sizeof(prgm->grid));
			ft_bzero(prgm->new, sizeof(prgm->grid));
			if (create_new_tile(prgm) == ERR_SQUARE_FULL)
			{
				sleep(1);
				if (game_lost(prgm) == EXIT_ON_LOST)
					exit_game(prgm);
			}
			display_grid(prgm);
		}
	}
	return (prompt_continue(prgm));
}
