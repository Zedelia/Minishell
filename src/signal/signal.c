/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:20:53 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/11 18:45:14 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//TODO handle "clear current process + start a new"
void sig_int(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	exit(signum);
}

//TODO (aka doesn't work at all, currently copy the shell without \n)
void sig_term(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	exit(signum);
}

void sig_quit(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	exit(0);
}
