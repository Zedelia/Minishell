//#include "includes/minishell.h"
#include "../includes/minishell.h"

char *get_env_var(char **env, char *varname);

//! WIP
int	arg_len(char *str, char sep)
{
	int i;
	int sepcount;

	i = 0;
	sepcount = is_in(sep, "\'\"") ? 0 : 1;
	while (str[i] && str[i] != sep)
	{
		if (is_in(str[i], "\'\""))
		{
			if (sep == str[i])
			{
				sep = ' ';
			}
			i++;
			sepcount++;
		}
		i++;
	}

}

//!WIP
//* Cuts an operation in args
// j will be used to make a simili strstr
// sep is the current separator : ' " or space
char *cut_args(char *str)
{
	int i;
	int j;
	char sep;

	i = 0;
	j = 0;
	sep = ' ';
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		//lstadd sur wrmalloc
		wrmalloc(arg_len(str + i, sep));
		j = i;
	}
}


int main(int ac, char **av, char **env)
{
	/*
	t_shell shell;
	int status;

	status = 1;
	shell.pwd = get_env_var(env, "PWD");

	while (status)
	{
		ft_printf("\n%s >>", shell.pwd);
		status = exec();
	}
	*/

	char *line = "echo 12\"12'\"";
	cut_args(line);

	(void)ac;
	(void)av;
	(void)env;
	return (0);
}