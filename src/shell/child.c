/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 12:15:21 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/11 12:04:59 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	child()
{
	t_input **head_input;
	char	*user_input;

	head_input = NULL;
	user_input = 0;
	ft_pwd(False);
	ft_printf(" >>> ");
	get_next_line(0, &user_input);
	input_init(head_input, user_input);


	// while (1)
	// 	sleep(1);
	ft_printf("Child out\n");
	exit(SUCCESS);
}
