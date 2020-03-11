/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:20:53 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/11 12:14:48 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sig_int(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	//TODO handle "clear current process + start a new"
}

//TODO (aka doesn't work at all)
void sig_term(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	if (signum == 2)
		exit(0);
}

void sig_quit(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	(void)signum;
	exit(0);
}
