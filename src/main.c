/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 09:34:50 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 11:36:37 by jotrique         ###   ########lyon.fr   */
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

// pid is the child PID for the parent, or 0 for the child
int main(int ac, char **av, char **env)
{
	int	status;

	pid_t pid = fork();
	if (pid == -1)
	{
		ft_printf("Error\nForking failed\n");
		return (-1);
	}

	// if (pid == 0)
	// 	child(&status);
	if (pid)
		parent(&status);

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