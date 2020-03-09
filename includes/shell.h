/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:22:45 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 13:55:29 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

//signal.c
void	sigint(int signum);
void	sigterm(int signum);
void	sigquit(int signum);

//parent.c
void	parent(int *status);

//input.c
int		input_init(t_input **head_input, char *user_input);
void	input_clear(t_input **head);

//return.c
int return_function(const char *func_name, const char *message);

#endif