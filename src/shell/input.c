/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:06:38 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/10 11:10:09 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_clear(t_input **head)
{
	t_input *current;

	while (*head)
	{
		current = (*head)->next;
		wrfree((*head)->content);
		(*head)->content = 0;
		cmd_clear(&(*head)->cmd);
		wrfree((*head));
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
	wrfree(user_input);
	input_add(head_input, new);
	input_join(&new);
	//ft_printf("%s\n", new->cmd->content);
	// return (cmd_init(new));

	wrdestroy();
	// input_clear(head_input);
	while (1)
	{
		ft_printf("Leaks me !\n");
		sleep(1);
	}
	return (1);
}
