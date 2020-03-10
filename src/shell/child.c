/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:15:21 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/10 11:47:49 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	child(t_input **head_input)
{
	char	*user_input;

	user_input = 0;
	ft_pwd(False);
	ft_printf(" >>> ");
	get_next_line(0, &user_input);
	input_init(head_input, user_input);
	ft_printf("HELOOOOOO\n");
	return(1);
}
