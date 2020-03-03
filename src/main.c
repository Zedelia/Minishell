//#include "includes/minishell.h"
#include "../includes/minishell.h"

char *get_env_var(char **env, char *varname);

int main(int ac, char **av, char **env)
{
	t_shell shell;

	shell.pwd = get_env_var(env, "PWD");
	ft_printf("\n%s >>", shell.pwd);

	(void)ac;
	(void)av;
	(void)env;
	return (0);
}