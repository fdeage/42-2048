/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:21:31 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 19:05:55 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game_2048.h"

/*
**	init_color(COLOR_BLACK,0,0,0);
**	init_color(COLOR_RED,1000,0,0);
**	init_color(COLOR_GREEN,0,1000,0);
**	init_color(COLOR_YELLOW,1000,1000,0);
**	init_color(COLOR_BLUE,0,0,1000);
**	init_color(COLOR_MAGENTA,1000,0,1000);
**	init_color(COLOR_CYAN,0,1000,1000);
**	init_color(COLOR_WHITE,1000,1000,1000);
*/

void	reinit_color(void)
{
	init_color(COLOR_BACK, 130, 130, 130);
	init_color(COLOR_0, 4 * 0xcc, 4 * 0xc0, 4 * 0xb3);
/*
	init_color(COLOR_2, 700, 0, 0);
	init_color(COLOR_4, 700, 0, 0);
	init_color(COLOR_8, 700, 0, 0);
	init_color(COLOR_16, 700, 0, 0);
	init_color(COLOR_32, 700, 0, 0);
	init_color(COLOR_ELSE, 700, 0, 0);
*/
}
