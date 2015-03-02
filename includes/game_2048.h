/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:07:00 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/01 23:24:03 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <time.h>
# include <ncurses.h>
# include "libft.h"

# define SQUARE_RANGE	4
# define SQUARE_SIZE_Y	12
# define SQUARE_SIZE_X	8
# define KEY_ESC		27

# define COLOR_0		COLOR_BLACK
# define COLOR_2		COLOR_WHITE
# define COLOR_4		COLOR_YELLOW
# define COLOR_8		COLOR_GREEN
# define COLOR_16		COLOR_BLUE
# define COLOR_32		COLOR_MAGENTA
# define COLOR_64		COLOR_CYAN
# define COLOR_ELSE		COLOR_RED

enum					e_const
{
	WIN_VALUE = 32
};

enum					e_ret_value
{
	RET_OK,
	ERR_INITSCR,
	ERR_MALLOC_FAILED,
	ERR_SQUARE_FULL,
	ERR_NO_COLOR,
	ERR_INIT_FAILED,
	KEY_ARROWS,
	MOVE_OK,
	NO_MOVE,
	REDIM_SIGNAL,
	NO_REDIM,
	EXIT_ON_LOST,
	CONTINUE_ON_LOST
};

enum					e_prompt_value
{
	CONTINUE_GAME,
	LEAVE_GAME,
};

enum					e_input
{
	INPUT_UP = 5,
	INPUT_DOWN = 4,
	INPUT_LEFT = 3,
	INPUT_RIGHT = 1,
	INPUT_UNKNOWN
};

typedef struct			s_tile
{
	int					value;
}						t_tile;

typedef struct			s_prgm
{
	t_tile				grid[SQUARE_RANGE][SQUARE_RANGE];
	t_tile				new[SQUARE_RANGE][SQUARE_RANGE];
	int					back_clr;
	int					i;
	int					dup;
	WINDOW				*win;
	int					width;
	int					height;
	int					highest;
	time_t				begin_time;
	size_t				score;
}						t_prgm;

/*
** run.c
*/

int						run_2048(t_prgm *prgm);

/*
** compute.c
*/

void					compute_new_state(t_prgm *prgm, int input, int cst);

/*
** display.c
*/

int						draw_init(void);
int						display_grid(t_prgm *prgm);

/*
** exit.c
*/

int						is_power_2(int value);
void					exit_on_signal(int signal);
void					exit_game(t_prgm *prgm);
int						game_lost(t_prgm *prgm);

/*
** new_tile.c
*/

int						create_new_tile(t_prgm *prgm);

/*
** redim.c
*/

int						redim_screen(int input);

/*
** get_color.c
*/

int						get_tile_color(int value);

/*
** reinit_color.c
*/

void					reinit_color(void);

#endif
