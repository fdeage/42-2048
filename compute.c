/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 18:05:28 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:07:39 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "game_2048.h"

#define I	(prgm->i)
#define DUP	(prgm->dup)

static void	cp_left_2(t_prgm *prgm, int y, int old, int new)
{
	while (old < SQUARE_RANGE)
	{
		DUP = 0;
		while (old < SQUARE_RANGE && (prgm->grid[y][old]).value == 0)
			++old;
		I = 1;
		while (old < SQUARE_RANGE - 1 && old + I < SQUARE_RANGE
			&& ((prgm->grid[y][old + I]).value == 0
			|| (prgm->grid[y][old + I]).value == (prgm->grid[y][old]).value))
		{
			if ((prgm->grid[y][old]).value == (prgm->grid[y][old + I]).value
				&& DUP == 0)
				DUP = I;
			++I;
		}
		if (old < SQUARE_RANGE && DUP == 0)
			(prgm->new[y][new++]).value = (prgm->grid[y][old++]).value;
		else if (old < SQUARE_RANGE)
		{
			(prgm->new[y][new++]).value = 2 * (prgm->grid[y][old + DUP]).value;
			old += DUP + 1;
		}
	}
	while (new < SQUARE_RANGE)
		(prgm->new[y][new++]).value = 0;
}

static void cp_right_2(t_prgm *prgm, int y, int old, int new)
{
	while (old >= 0)
	{
		DUP = 0;
		while (old >= 0 && (prgm->grid[y][old]).value == 0)
			--old;
		I = 1;
		while (old > 0 && old - I >= 0
			&& ((prgm->grid[y][old - I]).value == 0
			|| (prgm->grid[y][old]).value == (prgm->grid[y][old - I]).value))
		{
			if ((prgm->grid[y][old]).value == (prgm->grid[y][old - I]).value
				&& DUP == 0)
				DUP = I;
			++I;
		}
		if (old > -1 && DUP == 0)
			(prgm->new[y][new--]).value = (prgm->grid[y][old--]).value;
		else if (old > -1)
		{
			(prgm->new[y][new--]).value = 2 * (prgm->grid[y][old - DUP]).value;
			old -= DUP + 1;
		}
	}
	while (new >= 0)
		(prgm->new[y][new--]).value = 0;
}

static void cp_up_2(t_prgm *prgm, int x, int old, int new)
{
	while (old < SQUARE_RANGE)
	{
		DUP = 0;
		while (old < SQUARE_RANGE && (prgm->grid[old][x]).value == 0)
			++old;
		I = 1;
		while (old < SQUARE_RANGE - 1 && old + I < SQUARE_RANGE
			&& ((prgm->grid[old + I][x]).value == 0
			|| (prgm->grid[old][x]).value == (prgm->grid[old + I][x]).value))
		{
			if ((prgm->grid[old][x]).value == (prgm->grid[old + I][x]).value
				&& DUP == 0)
				DUP = I;
			++I;
		}
		if (old < SQUARE_RANGE && DUP == 0)
			(prgm->new[new++][x]).value = (prgm->grid[old++][x]).value;
		else if (old < SQUARE_RANGE)
		{
			(prgm->new[new++][x]).value = 2 * (prgm->grid[old + DUP][x]).value;
			old += DUP + 1;
		}
	}
	while (new < SQUARE_RANGE)
		(prgm->new[new++][x]).value = 0;
}

static void	cp_down_2(t_prgm *prgm, int x, int old, int new)
{
	while (old >= 0)
	{
		DUP = 0;
		while (old >= 0 && (prgm->grid[old][x]).value == 0)
			--old;
		I = 1;
		while (old > 0 && old - I >= 0
			&& ((prgm->grid[old - I][x]).value == 0
			|| (prgm->grid[old][x]).value == (prgm->grid[old - I][x]).value))
		{
			if ((prgm->grid[old][x]).value == (prgm->grid[old - I][x]).value
				&& DUP == 0)
				DUP = I;
			++I;
		}
		if (old > -1 && DUP == 0)
			(prgm->new[new--][x]).value = (prgm->grid[old--][x]).value;
		else if (old > -1)
		{
			(prgm->new[new--][x]).value = 2 * (prgm->grid[old - DUP][x]).value;
			old -= DUP + 1;
		}
	}
	while (new >= 0)
		(prgm->new[new--][x]).value = 0;
}

void		compute_new_state(t_prgm *prgm, int input, int cst)
{
	if (input == KEY_RIGHT)
	{
		while (cst < SQUARE_RANGE)
			cp_right_2(prgm, cst++, SQUARE_RANGE - 1, SQUARE_RANGE - 1);
	}
	else if (input == KEY_LEFT)
	{
		while (cst < SQUARE_RANGE)
			cp_left_2(prgm, cst++, 0, 0);
	}
	else if (input == KEY_UP)
	{
		while (cst < SQUARE_RANGE)
			cp_up_2(prgm, cst++, 0, 0);
	}
	else if (input == KEY_DOWN)
	{
		while (cst < SQUARE_RANGE)
			cp_down_2(prgm, cst++, SQUARE_RANGE - 1, SQUARE_RANGE - 1);
	}
	else if (input == KEY_ESC)
		exit_game(prgm);
}
