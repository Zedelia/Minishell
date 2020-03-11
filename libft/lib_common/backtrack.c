/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:07:17 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/11 19:15:07 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	backtrack(char *str)
{
	int len;

	len = ft_strlen(str) - 1;
	if (len == -1)
		return (str[0]);
	while (len > 0 && str[len] == ' ')
		len--;
	return (str[len]);
}
