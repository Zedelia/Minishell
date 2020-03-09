/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:15:21 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 11:51:23 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parent(int *status)
{
	char	*input = 0;

	ft_pwd(False);
	ft_printf(" >>> ");
	get_next_line(0, &input);
	ft_printf("input |%s|\n", input);
	(void)status;
}