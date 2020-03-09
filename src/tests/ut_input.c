#include "minishell.h"


void init_input(t_input **head_input, char *user_input);

int main(int ac, char **av)
{
	t_input *head_input = 0;
	char *user_input = ft_strdup("echo patate 1331234 w134");
	char *user_input2 = ft_strdup("ls | cat -e");
	t_input *current;

	input_init(&head_input, user_input);
	current = head_input;
	while (current)
	{
		ft_printf("f - %s\n", current->content);
		current = current->next;
	}

	input_init(&head_input, user_input2);
	current = head_input;
	while (current)
	{
		ft_printf("s - %s\n", current->content);
		current = current->next;
	}

	(void)ac;
	(void)av;
}
