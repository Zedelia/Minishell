/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:30:50 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/09 16:57:12 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char				*str;
	size_t				i;
	unsigned char		car;

	i = 0;
	str = b;
	car = (unsigned char)c;
	while (i < len)
	{
		*(str + i) = car;
		i++;
	}
	return (b);
}
