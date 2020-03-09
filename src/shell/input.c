/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:06:38 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 15:58:35 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_clear(t_input **head)
{
	t_input *current;

	while (*head)
	{
		current = (*head)->next;
		ft_memdel((void**)&(*head)->content);
		(*head)->content = 0;
		//TODO add cmd_clear();
		// cmd = 0;
		ft_memdel((void**)&(*head));
		*head = current;
	}
	head = 0;
}

void	input_add(t_input **head_input, t_input *new)
{
	t_input *tmp;

	if (head_input == 0)
		head_input = &new;
	else
	{
		tmp = *head_input;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

int		input_init(t_input **head_input, char *user_input)
{
	t_input *new;

	if (!(new = wrmalloc(sizeof(t_input))))
		return (return_function(__func__, "FAIL malloc"));
	new = &(t_input){0};
	new->content = ft_strdup(user_input);
	input_add(head_input, new);
	ft_memdel((void**)&user_input);
	cmd_init(new);
	//ft_printf("%s\n", new->cmd->content);
	// return (cmd_init(new));

	return (1);
}
