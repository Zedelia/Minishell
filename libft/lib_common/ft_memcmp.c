/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:14:39 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/09 16:56:53 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*sc1;
	const unsigned char	*sc2;

	i = 0;
	sc1 = s1;
	sc2 = s2;
	while (i < n)
	{
		if (*(sc1 + i) != *(sc2 + i))
			return (*(sc1 + i) - *(sc2 + i));
		i++;
	}
	return (0);
}
