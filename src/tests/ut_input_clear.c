#include "minishell.h"

int main(void)
{
	t_cmd *cmd1 = 0;
	t_cmd *cmd2 = 0;
	t_input part2 = (t_input){"part2", cmd2, 0};
	t_input part1 = (t_input){"part1", cmd1, &part2};
	t_input *phead = &part1;
	t_input **head = &phead;

	t_input *current = *head;

	while (current)
	{
		ft_printf("%s\n", current->content);
		current = current->next;
	}

	input_clear(head);

	current = *head;

	while (current)
	{
		ft_printf("%s\n", current->content);
		current = current->next;
	}

	while (1)
	{
		sleep(1);
	}
}