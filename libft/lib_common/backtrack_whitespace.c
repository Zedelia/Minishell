/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_ws.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 16:39:02 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 16:52:20 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	backtrack_ws(char c, char *str)
{
	int len;

	len = ft_strlen(str) - 1;
	while (len > 0 && is_in(str[len], " \t\n\r\v\f"))
		len--;
	return (str[len] == c ? 1 : 0);
}
