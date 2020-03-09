/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:06:38 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 16:38:46 by jotrique         ###   ########lyon.fr   */
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
		cmd_clear(&(*head)->cmd);
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

int		input_parser(t_input *input)
{
	char *str;
	char sep;
	int i;
	int j;

	i = 0;
	j = 0;
	str = input->content;
	while(str[i])
	{
		if (is_in(str[i], "\'\""))
		{
			sep = str[i];
			while (str[i] && str[i] != sep)
				i++;
			if (!str[i])
				return (return_function(__func__, "Quote still opened\n"));			// cas d'erreur, fin de ligne avec ' ou " ouvert
		}
		if (str[i] == ';' && i > 0 && str[i - 1] != '\\')
		{
			cmd_init(input, &str[j], i - j);
			j = i + 1;
		}
		i++;
	}
	if (backtrack_whitespace('|', str, i) == True)
		return (UNDEFINED);
	return (SUCCESS);
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
	input_parser(new);
	//ft_printf("%s\n", new->cmd->content);
	// return (cmd_init(new));

	return (1);
}
