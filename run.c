/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:38:28 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:12:14 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ncurses.h>
#include "game_2048.h"
#include "libft.h"

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
	char	buf[16];
	char	*score;
	int		ret;

	(void)prgm;
	ft_bzero(buf, 16);
	ft_putstr_color("You reached ", COL_LIGHT_GREEN);
	score = ft_itoa(prgm->highest);
	ft_putstr_color(score, COL_GREEN);
	free(score);
	ft_putstr_color("! Continue ? [Y/N]", COL_LIGHT_GREEN);
	ret = 1;
	while ((ret = read(0, &buf, 16)) == 1)
	{
		ret = 0;
		if (ft_strcmp("Y", buf))
			return (CONTINUE_GAME);
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

	while (prgm->highest < WIN_VALUE)
	{
		input = getch();
		if (redim_screen(input) == REDIM_SIGNAL)
			display_grid(prgm);
		if (handle_input(prgm, input) == KEY_ARROWS
			&& ft_memcmp(prgm->new, prgm->grid, sizeof(prgm->grid)) != 0)
		{
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
