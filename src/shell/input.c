/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:06:38 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 13:52:19 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include "../../includes/minishell.h"

void	input_clear(t_input **head)
{
	t_input *current;

	while (*head)
	{
		current = (*head)->next;
		free((*head)->content);
		(*head)->content = 0;
		//TODO add cmd_clear();
		// cmd = 0;
		free(*head);
		*head = current;
	}
	head = 0;
}

int		input_init(t_input **head_input, char *user_input)
{
	t_input *current;

	current = 0;
	if (*head_input == 0)
	{
		if (!(*head_input = wrmalloc(sizeof(t_input))))
			return (return_function(__func__, "FAIL malloc"));
		**head_input = (t_input){0};
		(*head_input)->content = ft_strdup(user_input);
	}
	else
	{
		current = *head_input;
		while (current->next)
			current = current->next;
		if (!(current->next = wrmalloc(sizeof(t_input))))
			return (return_function(__func__, "FAIL malloc"));
		*current->next = (t_input){0};
		current->next->content = ft_strdup(user_input);
	}
	free(user_input);
	user_input = 0;
	return (init_command(*head_input));
}