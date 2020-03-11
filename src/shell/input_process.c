/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:12:00 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/11 13:24:29 by mbos             ###   ########lyon.fr   */
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
		if (str[i] == ';' && i > 0 && str[i - 1] != '\\')
		{
			cmd_init(input, &str[j], i - j);
			j = i + 1;
		}
		i++;
	}
	cmd_init(input, &str[j], i - j);
}

t_bool	is_quote_opened(char *str, char sep)
{
	int i;

	i = 1;
	while (str[i] && str[i] != sep)
		i++;
	if (!str[i])
		return (True);
	return (False);
}

int		input_quote_check(t_input *input)
{
	char *str;
	int i;
	int j;

	i = -1;
	j = 0;
	str = input->content;
	while(str[++i])
	{
		if (is_in(str[i], "\'\"") && is_quote_opened(str + i, str[i]) == True)
			return (return_function(__func__, "Quote still opened\n"));
	}
	return (SUCCESS);
}

int		input_join(t_input **input)
{
	char *user_input;
	char *cp;

	input_quote_check(*input);
	if (backtrack_ws('|', (*input)->content) == False)
		return (SUCCESS);
	ft_printf("> ");
	get_next_line(0, &user_input);
	cp = (*input)->content;
	(*input)->content = ft_strjoin(cp, user_input);
	wrfree(cp);
	return (input_join(input));
}
