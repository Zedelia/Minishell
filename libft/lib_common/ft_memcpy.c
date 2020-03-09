/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:56:05 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/09 16:56:58 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*des;
	const unsigned char		*srt;
	size_t					i;

	if (src == 0 && dest == 0)
		return (0);
	des = dest;
	srt = src;
	i = 0;
	while (i < n)
	{
		*(des + i) = *(srt + i);
		i++;
	}
	return (dest);
}
