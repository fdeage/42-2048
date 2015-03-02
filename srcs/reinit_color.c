/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinit_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:21:31 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 22:16:11 by fdeage           ###   ########.fr       */
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

static int	r(int value)
{
	return ((value * 1000) / 256);
}

static void	reinit_front_colors(void)
{
	init_color(COLOR_F_0, r(0x22), r(0x22), r(0x22));
	init_color(COLOR_F_2, r(0x22), r(0x22), r(0x22));
	init_color(COLOR_F_4, r(0x22), r(0x22), r(0x22));
	init_color(COLOR_F_8, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_16, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_32, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_64, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_128, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_256, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_512, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_1024, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_2048, r(0x77), r(0x6e), r(0x65));
	init_color(COLOR_F_4096, r(0x77), r(0x6e), r(0x65));
}

void		reinit_colors(void)
{
	reinit_front_colors();
	init_color(COLOR_BACK, r(0x20), r(0x20), r(0x20));
	init_color(COLOR_B_0, r(0x20), r(0x20), r(0x20));
	init_color(COLOR_B_2, r(0xee), r(0xf4), r(0xfa));
	init_color(COLOR_B_4, r(0xed), r(0xe0), r(0xc8));
	init_color(COLOR_B_8, r(0xf2), r(0xb1), r(0x79));
	init_color(COLOR_B_16, r(0xf5), r(0x95), r(0x63));
	init_color(COLOR_B_32, r(0xf6), r(0x7c), r(0x5f));
	init_color(COLOR_B_64, r(0xf6), r(0x5e), r(0x3b));
	init_color(COLOR_B_128, r(0xed), r(0xcf), r(0x72));
	init_color(COLOR_B_256, r(0xed), r(0xcc), r(0x61));
	init_color(COLOR_B_512, r(0xed), r(0xc8), r(0x50));
	init_color(COLOR_B_1024, r(0xed), r(0xc5), r(0x3f));
	init_color(COLOR_B_2048, r(0xed), r(0xc2), r(0x20));
	init_color(COLOR_B_4096, r(0x3c), r(0x3a), r(0x32));
}
