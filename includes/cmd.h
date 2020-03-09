/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbos <mbos@student.le-101.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:56:07 by mbos              #+#    #+#             */
/*   Updated: 2020/03/09 16:29:04 by mbos             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "minishell.h"

int		cmd_init(t_input *input, char *content, size_t len);
void	cmd_clear(t_cmd **head);

#endif