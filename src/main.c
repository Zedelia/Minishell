/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:34:50 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/11 12:03:35 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
t_global *global(void)
{
	static t_global boop;
	return (&boop);
}
*/

int		getset_pid(int pid)
{
	static int child_pid;

	if (pid != 0)
		child_pid = pid;
	return (child_pid);
}

/* test of a signal_handler function (second arg of signal function) that use the child pid to kill itself
void	sig_call(int signum)
{
	int pid;

	ft_printf("signum %d\n", signum);
	pid = getset_pid(0);
	if (pid != 0)
		kill(pid, SIGKILL);
}
*/

// pid is the child PID for the parent, or 0 for the child
int		main(int ac, char **av, char **env)
{
	int w;

	pid_t pid = fork();
	if (pid == -1)
	{
		ft_printf("Error\nForking failed\n");
		return (-1);
	}

	if (pid == 0)
	{
		signal(SIGINT, sig_int);
		signal(SIGTERM, sig_term);
		signal(SIGQUIT, sig_quit);
		child();
		exit(1);
	}
	if (pid)
	{
		// getset_pid(pid);					// share the child pid to other function with a getter/setter, OOP style
		w = waitpid(-1, 0, 0);				// can change the second param to a int pointer, status
		// w is the pid of the child that acted out
		kill(pid, SIGKILL);
		// parent();						// nothing happens in parent so far, put waitpid and all this things inside parent when tests are over
		ft_printf("Parent out\n");
	}

	(void)pid;
	(void)ac;
	(void)av;
	(void)env;
	return (0);
}

/*
int main(int ac, char **av, char **env)
{
	int	status;
	int	w;

	// pid is the child PID for the parent, or 0 for the child
	pid_t pid = fork();
	if (pid == -1)
	{
		printf("Error\nForking failed\n");
		return (-1);
	}

	// child
	if (pid == 0)
	{
		// init the signal, so it knows where to send the SIGINT
		signal(SIGINT, sigint);
		signal(SIGTERM, sigterm);
		signal(SIGQUIT, sigquit);

		// Code happens here
		//! Input level
		while (1)
		{
			printf("I'm the child ! Kill me please ! Ctrl+ C, D or \\ !\n");
			sleep(1);
		}
	}

	// parent
	if (pid)
	{
		//! Shell level
		print_current_path();
		w = waitpid(-1, &status, 0);
		if (w == -1)
		{
			printf("Error\nwaitpid failure\n");
		}
		printf("parent - waitpid statue %d\n", status);
		printf("I'm the parent\n");
	}
	printf("End reached\n");

	(void)ac;
	(void)av;
	(void)env;
	return (0);
}
*/