// gcc -Wall -Wextra -Werror bidouilles/ut_builtins.c src/builtins.c libft/libft.a && ./a.out

#include "../includes/minishell.h"
#include "../includes/jotrique_part.h"

int main(int ac, char **av, char **env)
{
	//ft_printf("\nEnv\n\n");
	//ft_env(env);

	ft_printf("\nExport ~\n\n");

	ft_export(env, "NOTanEQUALsign");
	ft_export(env, "FROMAGE=délice sur tartine");
	ft_export(env, "BOUYAH=poulpette colorée");
	ft_export(env, "CASHMONEY=yeux de gorgone");
	ft_export(env, "FROMAGE=poop sur tartine");
	ft_env(env);
	// ft_printf("\nUnset\n\n");
	// ft_unset(env, "FROMAGE");
	// ft_env(env);
	// ft_printf("\nPWD\n\n");
	//ft_pwd(env);
	(void)ac;
	(void)av;
	return (0);
}