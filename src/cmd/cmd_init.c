/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:54:49 by mbos              #+#    #+#             */
/*   Updated: 2020/03/11 16:18:33 by jotrique         ###   ########lyon.fr   */
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

// on avait copié cmd_add sur input_add, sauf que l'on avait un **head_input,
// mais pas de **head_cmd, donc ca couillait
// je l'ai passé en pointeur simple et maintenant ca marche ^^
void	cmd_add(t_cmd *head_cmd, t_cmd *new)
{
	t_cmd *tmp;

	if (!head_cmd)
		head_cmd = new;
	else
	{
		tmp = head_cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		cmd_init(t_input *input, char *content, int len)
{
	t_cmd *new;

	if (!(new = malloc(sizeof(t_cmd))))
		return (return_function(__func__, "FAIL malloc"));
	new->content = ft_strndup(content, len);
	// a test if you need one : ft_printf("\nStatus at cmd_init start\n\n*input-content %s\ncontent %s\nlen %d\n", input->content, content, len);
	cmd_add(input->cmd, new);
	cmd_parser(new);
	return (SUCCESS);
}
