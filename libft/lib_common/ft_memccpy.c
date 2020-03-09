/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:20:44 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/09 16:56:36 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char			*des;
	const unsigned char		*srt;
	size_t					i;
	int						compt;

	if (src == 0 && dest == 0)
		return (0);
	des = dest;
	srt = src;
	compt = 0;
	i = 0;
	while (i < n)
	{
		*(des + i) = *(srt + i);
		i++;
		if (*(srt + i) == (unsigned char)c && i < n)
		{
			*(des + i) = *(srt + i);
			compt = 1;
			break ;
		}
	}
	if (compt == 0)
		return (0);
	return (dest + i + 1);
}
