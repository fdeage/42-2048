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
	size_t	content_size;
	void	*content;
	t_list	*next;
	t_list	*prev;
};

#endif
