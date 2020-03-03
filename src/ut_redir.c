// gcc -Wall -Wextra -Werror bidouilles/ut_redir.c src/redir.c libft/libft.a && ./a.out

#include "../includes/minishell.h"
#include "../includes/jotrique_part.h"

//!EVERYTHING IS WIP

int main(int ac, char **av, char **env)
{
	//ft_echo
	//ft_echo("Boop", 2);

	// parse_command
	t_list **po;
	t_list *current;

	po = parse_command("echo 12 43 \"patate\" \'boop\'");
	ft_printf("AHAHA I'M ALIVE ! MINION !\n");
	current = *po;

	int i = 0;
	while (current)
	{
		ft_printf("|%d| ~ %s\n", i, current->content);
		i++;
		current = current->next;
	}

	// parse_arg is WIP, comment it in parse_command and just return type
	//t_parsed_command pc;
	//parse_arg(&pc, "echo 42", 5);
	//put printfs in it
	(void)ac;
	(void)av;
	(void)env;
	return (0);
}