/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:20:53 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 10:25:32 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigint(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	if (signum == 2)
		exit(0);
}

//TODO (aka doesn't work at all)
void sigterm(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	if (signum == 2)
		exit(0);
}

void sigquit(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	if (signum == 3)
		exit(0);
}
