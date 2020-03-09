/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:15:21 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 14:43:07 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child(int *status)
{
	t_input **head_input;
	char	*user_input;

	*head_input = 0;
	user_input = 0;
	ft_pwd(False);
	ft_printf(" >>> ");
	get_next_line(0, &user_input);
	printf("%d\n", input_init(head_input, user_input));
	ft_printf("input |%s|\n", user_input);
	(void)status;
}
