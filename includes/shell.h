/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:22:45 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 11:16:18 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

//signal.c
void sigint(int signum);
void sigterm(int signum);
void sigquit(int signum);

//parent.c
void parent(int *status);

#endif