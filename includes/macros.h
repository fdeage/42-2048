/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 11:48:38 by fdeage            #+#    #+#             */
/*   Updated: 2015/02/05 11:49:24 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/*
** ERROR_PRINTING_MODE:
** 0 (STD_MODE): standard mode
** 1 (DEBUG_MODE): debug mode, with non-compliant messages
** --> has to be put on 0 before pushing the project!!
** colors can be combined: "\033[41;4;32m"
*/

# ifndef NULL
#  define NULL					((void *)0)
# endif

/*
** I/O define
*/
# define STDIN					0
# define STDOUT					1
# define STDERR					2

/*
** Boolean flags
*/
# define TRUE					1
# define FALSE					0

# define ERROR_PRINTING_MODE	1

# define COL_RESET				"\033[0m"
# define COL_UNDERLINED			"\033[4m"
# define COL_REVERSE			"\033[7m"
# define COL_BLACK				"\033[22;30m"
# define COL_RED				"\033[22;31m"
# define COL_GREEN				"\033[22;32m"
# define COL_YELLOW				"\033[22;33m"
# define COL_BLUE				"\033[22;34m"
# define COL_MAGENTA			"\033[22;35m"
# define COL_CYAN				"\033[22;36m"
# define COL_WHITE				"\033[1;37m"
# define COL_GRAY				"\033[1;30m"
# define COL_LIGHT_GRAY			"\033[22;37m"
# define COL_LIGHT_RED			"\033[1;31m"
# define COL_LIGHT_GREEN		"\033[1;32m"
# define COL_LIGHT_YELLOW		"\033[1;33m"
# define COL_LIGHT_BLUE			"\033[1;34m"
# define COL_LIGHT_MAGENTA		"\033[1;35m"
# define COL_LIGHT_CYAN			"\033[1;36m"
# define COL_BACK_RED			"\033[41m"
# define COL_BACK_GREEN			"\033[42m"
# define COL_BACK_YELLOW		"\033[43m"
# define COL_BACK_BLUE			"\033[44m"
# define COL_BACK_MAGENTA		"\033[45m"
# define COL_BACK_CYAN			"\033[46m"

/*
** ERROR(s1, s2, st, rt, fd):
** error string s1, error string s2 (optional), status of error (STD, DEBUG),
** return value, fildes to print on;
** use the DEBUG macro for a simple use:
** DEBUG by default puts a DEBUG_MODE status, returns -1 and prints on sdout
*/

# define E1(x)				err1(x, __FILE__, __func__, __LINE__)
# define ERR_I(s1, s2, st, rt, fd)	ft_err_i(E1(err2(s1, s2, st)), rt, fd)
# define ERR_P(s1, s2, st, rt, fd)	ft_err_p(E1(err2(s1, s2, st)), rt, fd)
# define DEBUG_END			__FILE__, __func__, __LINE__), EXIT_FAILURE, 1
# define DBG_I(s1, s2)		ft_err_i(err1(err2(s1, s2, DEBUG_MODE), DEBUG_END)
# define DBG_P(s1, s2)		ft_err_p(err1(err2(s1, s2, DEBUG_MODE), DEBUG_END)

enum		e_err_status
{
	DEBUG_MODE = 0,
	STD_MODE = 1
};
# undef false
# undef true

enum		e_bool
{
	false = 0,
	true = 1
};

typedef struct s_list		t_list;
typedef struct s_error		t_error;
typedef enum e_err_status	t_err_status;
typedef enum e_bool			t_bool;

struct		s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
	t_list	*prev;
};

struct		s_error
{
	const char		*msg1;
	const char		*msg2;
	t_err_status	status;
	const char		*file;
	const char		*func;
	int				line;
};

#endif
