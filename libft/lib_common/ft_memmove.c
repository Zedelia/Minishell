/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:10:26 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/09 16:57:07 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*des;
	const char		*srccpy;
	int				i;

	if (src == 0 && dest == 0)
		return (0);
	des = dest;
	srccpy = src;
	if (des < srccpy)
	{
		i = -1;
		while (++i < (int)n)
			des[i] = srccpy[i];
	}
	else
	{
		i = (int)(n - 1);
		while (i > -1)
		{
			des[i] = srccpy[i];
			i--;
		}
	}
	return (dest);
}
