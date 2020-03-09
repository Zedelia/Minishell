/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:15:21 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 12:16:18 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void child(int *status)
{
	t_input **head_input;
	char	*user_input = 0;

	ft_pwd(False);
	ft_printf(" >>> ");
	get_next_line(0, &user_input);
	init_input(head_input, user_input);
	ft_printf("input |%s|\n", user_input);
	(void)status;
}