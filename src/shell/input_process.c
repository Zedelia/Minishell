/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:12:00 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/11 19:15:46 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		input_parser(t_input *input)
{
	int i;
	int j;
	char quote_type;

	i = 0;
	j = 0;
	while (input->content[i])
	{
		if (is_in(input->content[i], "\'\""))
		{
			quote_type = input->content[i++];
			while (input->content[i] && input->content[i] != quote_type)
				i++;
		}
		if (input->content[i] == ';' && i > 0 && input->content[i - 1] != '\\')
		{
			cmd_init(input, &input->content[j], i - j);
			j = i + 1;
		}
		i++;
	}
	cmd_init(input, &input->content[j], i - j);
	//TODO Definier une return value, j'en ai mis une pour pouvoir compiler
	return (SUCCESS);
}

// j'ai refusionner input_quote_check et quote_opened, ils ne marchaient pas separement
int		input_quote_check(t_input *input)
{
	char *str;
	int i;
	int j;
	char quote_type;

	i = -1;
	j = 0;
	str = input->content;
	while(str[++i])
	{
		if (is_in(input->content[i], "\'\""))
		{
			quote_type = input->content[i++];
			while (input->content[i] && input->content[i] != quote_type)
				i++;
		}
		if (!str[i])
			return (return_function(__func__, "Quote still opened\n"));
	}
	return (SUCCESS);
}

int		input_join(t_input **input)
{
	char *user_input;
	char *cp;

	input_quote_check(*input);
	if (backtrack((*input)->content) != '|')
		return (SUCCESS);
	ft_printf("> ");
	get_next_line(0, &user_input);
	cp = (*input)->content;
	(*input)->content = ft_strjoin(cp, user_input);
	wrfree(cp);
	return (input_join(input));
}
