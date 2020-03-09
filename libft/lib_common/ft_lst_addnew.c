/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:52:13 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/09 16:55:43 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_lst_addnew(t_list **first_elem, char *content)
{
	t_list	*new_elem;

	if (!(new_elem = ft_lstnew(content)))
		return (0);
	ft_lstadd_back(first_elem, new_elem);
	return (1);
}
