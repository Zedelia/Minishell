/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 10:22:45 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/11 12:15:09 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include "minishell.h"

//signal.c
void	sig_int(int signum);
void	sig_term(int signum);
void	sig_quit(int signum);

//parent.c
void	parent(void);

//child.c
int		child(t_input **head);

//input_process.c
int		input_parser(t_input *input);
int		input_join(t_input **input);

//input.c
int		input_init(t_input **head_input, char *user_input);
void	input_clear(t_input **head);

//return.c
int		return_function(const char *func_name, const char *message);

#endif