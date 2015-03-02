/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 23:07:00 by fdeage            #+#    #+#             */
/*   Updated: 2015/03/02 23:54:46 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <time.h>
# include <ncurses.h>
# include "libft.h"

# define SQUARE_RANGE	6
# define SQUARE_SIZE_Y	16
# define SQUARE_SIZE_X	8
# define KEY_ESC		27

# define COLOR_BACK		204

# define COLOR_F_0		206
# define COLOR_F_2		207
# define COLOR_F_4		208
# define COLOR_F_8		209
# define COLOR_F_16		210
# define COLOR_F_32		211
# define COLOR_F_64		212
# define COLOR_F_128	213
# define COLOR_F_256	214
# define COLOR_F_512	215
# define COLOR_F_1024	216
# define COLOR_F_2048	217
# define COLOR_F_4096	218

# define COLOR_B_0		219
# define COLOR_B_2		220
# define COLOR_B_4		221
# define COLOR_B_8		222
# define COLOR_B_16		223
# define COLOR_B_32		224
# define COLOR_B_64		225
# define COLOR_B_128	226
# define COLOR_B_256	227
# define COLOR_B_512	228
# define COLOR_B_1024	229
# define COLOR_B_2048	230
# define COLOR_B_4096	231

# define COLOR_TEXT		136

#define TXT_X			((SQUARE_RANGE + 1) * (SQUARE_SIZE_Y) + 1)
#define TXT_Y			((SQUARE_RANGE + 1) * (SQUARE_SIZE_X) + 2)

enum					e_const
{
	WIN_VALUE = 16
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
	int					clr_pair;
	int					i;
	int					dup;
	WINDOW				*win;
	int					n;
	int					width;
	int					height;
	int					cont;
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

void					reinit_colors(void);

#endif
