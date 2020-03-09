/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:52:50 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 14:31:10 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "styles.h"

int return_function(const char *func_name, const char *message)
{
	ft_printf(RED"%s"RESET, func_name);
	if (message)
		ft_printf(": %s\n", message);
	perror(0);
	wrdestroy();
	return (-1);
}
