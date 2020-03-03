/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   minishell.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jotrique <jotrique@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/02/03 10:27:27 by jotrique     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/17 08:29:09 by jotrique    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//TODO Ce .h est pour les choses utilisées a la fois dans le parsing et le process
//* Proposition : Faire un tableau de fonction pour ce que le parsing file au process

#ifndef MINIHSELL_H
# define MINIHSELL_H

#include "../libft/include/libft.h"
#include "../libft/include/get_next_line.h"
#include "../libft/include/ft_printf.h"

/*
**	malloc, free
*/
# include <stdlib.h>

/*
**	write, read, close, fork, getcwd, execve, dup, dup2, pipe
*/
# include <unistd.h>

/*
**	open
*/
# include <fcntl.h>

/*
**	read
*/
# include <sys/types.h>
# include <sys/uio.h>

/*
**	wait, wait3, wait4, waitpid
*/
# include <sys/wait.h>

/*
**	signal, kill
*/
# include <signal.h>

/*
**	stat, lstat, fstat
*/
# include <sys/stat.h>

/*
**	opendir, readdir, closedir
*/
# include <dirent.h>

/*
**	errno
*/
# include <sys/errno.h>

/*
**	strerror
*/
# include <stdio.h>

enum e_command
{
	__echo = 0,
	__cd,
	__pwd,
	__export,
	__unset,
	__env,
	__exit,
	__size
};

#endif