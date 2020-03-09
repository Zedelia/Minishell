/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:21:29 by abourbou          #+#    #+#             */
/*   Updated: 2020/03/09 16:56:01 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_elem;
	t_list	*next_elem;

	if (!lst || !(*lst) || !del)
		return ;
	current_elem = *lst;
	while (current_elem)
	{
		next_elem = current_elem->next;
		del(current_elem->content);
		wrfree(current_elem);
		current_elem = next_elem;
	}
	*lst = 0;
}
