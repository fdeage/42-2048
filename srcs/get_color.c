/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 22:11:58 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 22:12:39 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
** cannot store more than 256 pairs...
*/

int	get_tile_color(int value)
{
	if (value == 0)
		return (134);
	else if (value == 256)
		return (129);
	else if (value == 512)
		return (130);
	else if (value == 1024)
		return (131);
	else if (value == 2048)
		return (132);
	else if (value == 4096)
		return (133);
	return (value);
}
