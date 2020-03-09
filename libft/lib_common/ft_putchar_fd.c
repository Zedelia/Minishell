/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:06:52 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/09 16:57:18 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
