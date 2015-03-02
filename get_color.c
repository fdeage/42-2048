/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:11:58 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:10:30 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
**        COLOR_BLACK   0
**       COLOR_RED     1
**      COLOR_GREEN   2
**      COLOR_YELLOW  3
**      COLOR_BLUE    4
**      COLOR_MAGENTA 5
**      COLOR_CYAN    6
**      COLOR_WHITE   7
*/

int	get_tile_color(int value)
{
	if (value == 0)
		return (COLOR_0);
	else if (value == 2)
		return (COLOR_2);
	else if (value == 4)
		return (COLOR_4);
	else if (value == 8)
		return (COLOR_8);
	else if (value == 16)
		return (COLOR_16);
	else if (value == 32)
		return (COLOR_32);
	else if (value == 64)
		return (COLOR_64);
	return (COLOR_ELSE);
}
