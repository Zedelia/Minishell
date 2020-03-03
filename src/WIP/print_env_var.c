/*
** The = sign is used as a terminator
** i.e : if you have HOME and HOMEBREW, it allows only HOME
*/

#include "../../includes/minishell.h"

/*
void	print_env_var(char **env, char *varname)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], ft_strjoin(varname, "="), ft_strlen(varname)))
			ft_printf("%s\n", env[i]);
		i++;
	}
}

void	ft_pwd(char **env)
{
	print_env_var(env, "PWD");
}
*/

char	*get_env_var(char **env, char *varname)
{
	int i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], ft_strjoin(varname, "="), ft_strlen(varname)))
			return (ft_strdup(env[i] + ft_strlen(varname) + 1));
		i++;
	}
	return (0);
}
