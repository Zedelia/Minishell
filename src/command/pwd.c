/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:43:20 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 11:46:36 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_bool command)
{
	char *cwd = 0;
	cwd = getcwd(cwd, 256 * 8);
	ft_printf("%s", cwd);
	if (command == True)
		ft_printf("\n");
	free(cwd);
}