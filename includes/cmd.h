/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:56:07 by mbos              #+#    #+#             */
/*   Updated: 2020/03/11 15:47:07 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "minishell.h"

int		cmd_init(t_input *input, char *content, int len);
int		cmd_parser(t_cmd *cmd);
void	cmd_add(t_cmd *head_cmd, t_cmd *new);
void	cmd_clear(t_cmd **head);


#endif