/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 17:12:00 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 18:09:20 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int		input_parser(t_input *input)
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
		if (str[i] == ';' && i > 0 && str[i - 1] != '\\')
		{
			cmd_init(input, &str[j], i - j);
			j = i + 1;
		}
	}
	return (SUCCESS);
}

int		input_join(t_input **input)
{
	char *user_input;
	char *cp;

	input_parser(*input);
	if (backtrack_ws('|', (*input)->content) == False)
		return (SUCCESS);
	ft_printf("> ");
	get_next_line(0, &user_input);
	// if (is_quote_opened(user_input))
	// 	return (return_function(__func__, "Quote still opened\n"));
	cp = (*input)->content;
	(*input)->content = ft_strjoin(cp, user_input);
	wrfree(cp);
	return (input_join(input));
}