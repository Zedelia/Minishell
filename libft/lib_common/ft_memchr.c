/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:22:28 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/09 16:56:47 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char			*strcpy;
	unsigned int	i;

	strcpy = (char *)str;
	i = 0;
	while (i < n)
	{
		if (strcpy[i] == c)
			return (strcpy + i);
		i++;
	}
	return (0);
}
