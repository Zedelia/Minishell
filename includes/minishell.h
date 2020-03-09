/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:27:27 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 15:11:13 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


//TODO Ce .h est pour les choses utilisées a la fois dans le parsing et le process
//* Proposition : Faire un tableau de fonction pour ce que le parsing file au process

#ifndef MINIHSELL_H
# define MINIHSELL_H

#include "../libft/include/libft.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

//	wait, wait3, wait4, waitpid
# include <sys/wait.h>

//	signal, kill
# include <signal.h>

//	stat, lstat, fstat
# include <sys/stat.h>

//	opendir, readdir, closedir
# include <dirent.h>

//	errno
# include <sys/errno.h>

//	strerror
# include <stdio.h>

# define SUCCESS 1
# define UNDEFINED 0
# define FAILURE -1

typedef enum
{
	False,
	True,
}	t_bool;

typedef struct s_global		t_global;
typedef struct s_shell 		t_shell;
typedef struct s_input 		t_input;
typedef struct s_cmd		t_cmd;
typedef struct s_op			t_op;
typedef struct s_args 		t_args;

struct s_global
{
	char *cwd;
};

struct s_shell
{
	t_input		*input;
};

struct s_input
{
	char	*content;
	t_cmd	*cmd;
	t_input	*next;
};

struct s_cmd
{
	char 	*content;
	t_op	*op;
	t_cmd	*next;
};

struct s_args
{
	char	*content;
	int		id;
	t_args	*next;
};

// main.c
// t_global *global(void);

# include "cmd.h"
# include "shell.h"
# include "exec.h"

#endif