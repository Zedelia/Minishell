/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:54:49 by mbos              #+#    #+#             */
/*   Updated: 2020/03/11 12:35:31 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_clear(t_cmd **head)
{
	t_cmd *current;

	while (*head)
	{
		current = (*head)->next;
		wrfree((*head)->content);
		(*head)->content = 0;
		//TODO add op_clear();
		// op = 0;
		wrfree((*head));
		*head = current;
	}
	head = 0;
}

int		cmd_init(t_input *input, char *content, size_t len)
{
	t_cmd *new;
	t_cmd *tmp;

	if (!(new = malloc(sizeof(t_cmd))))
		return (return_function(__func__, "FAIL malloc"));
	new->content = ft_strndup(content, len);
	if (!input->cmd)
		input->cmd = new;
	else
	{
		tmp = input->cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (SUCCESS);
}
