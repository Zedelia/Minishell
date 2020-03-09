/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 11:15:21 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 15:23:42 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parent(int *status)
{
	int w;

	w = waitpid(-1, status, 0);
	ft_printf("Parent ends");
	// ft_printf("Parent here : status = |%d|\nw = |%d|\n", *status, w);
}