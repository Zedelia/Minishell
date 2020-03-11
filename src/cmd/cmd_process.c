/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 13:30:29 by mbos              #+#    #+#             */
/*   Updated: 2020/03/11 18:48:53 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Melo :
find_cmd
	passer les blancs
	guillemets ? bool true
	./ ? => traitement exec DIIIIRECT
Jo :
Split arg 1
	(skip whitespace, '" check, nom dans tableau ou ./{*})
If nom !dans tableau -> Error, fuck le reste de la cmd, return (FAILURE)
Else split arg 2 et + et go operations

Verif si fini par pipe -> redirection stdout de la cmd
*/

int		cmd_parser(t_cmd *cmd)
{
	int i;
	int j;
	char sep;
	char *str;

	i = 0;
	j = 0;
	sep = 'n';
	str = cmd->content;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (is_in(str[i], "\'\""))
			sep = str[i];
		j = i;
		while (str[i] && !is_in(str[i], " \'\""))
			i++;
		ft_printf("cmd_parser : |%s|\n", ft_strndup(str + j, i));
		break ;
		i++;
	}
	return (SUCCESS);
}
// ft_printf("cmd_parser reached even if status 11\n");