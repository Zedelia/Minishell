/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotrique <jotrique@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 10:29:39 by jotrique          #+#    #+#             */
/*   Updated: 2020/03/09 11:29:30 by jotrique         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

/*
** TODO pour tous : ne pas comparer le dernier env_var (le path)
*/

int		ft_echo(char *arg, int fd_out)
{
	int len;

	len = ft_strlen(arg);
	len = write(fd_out, arg, len);
	if (len <= 0)
		return (1);
	return (0);
}

int		ft_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

/*
** A mettre dans libft ?
*/
int		char_index(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

/*
** Version qui prend toute l'assignation VAR=VALUE
*/

int		ft_export(char **env, char *env_var)
{
	int		i;
	char	*tmp;

	if (!is_in('=', env_var))
		return (0);
	i = 0;
	tmp = 0;
	while (env[i])
	{
		if (strncmp(env[i], env_var, char_index(env_var, '=')) == 0)
		{
			tmp = env[i];
			env[i] = ft_strdup(env_var);
			free(tmp);
			return (0);
		}
		i++;
	}
	tmp = env[i];
	env[i] = ft_strdup(env_var);
	env[i + 1] = tmp;
	return (0);
}

/*
** There's no error handling for unset with invalid argument
** It's a feature, it's the shell behaviour
*/

int		ft_unset(char **env, char *env_var_name)
{
	int		i;
	char	*old;

	i = 0;
	while (env[i + 1] && strncmp(env[i], env_var_name,
								ft_strlen(env_var_name) + 1) != 0)
		i++;
	if (env[i])
	{
		old = env[i];
		env[i] = env[i + 1];
		free(old);
		i = i + 1;
		while (env[i + i])
		{
			env[i] = env[i + 1];
			i++;
		}
	}
	return (0);
}

/*
** cd - modifier pwd a chaque fois
*/

int		ft_pwd(char *pwd)
{
	ft_printf("%s", pwd);
	return (0);
}
