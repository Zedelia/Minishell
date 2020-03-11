#include "minishell.h"

int main(void)
{
	t_input head = (t_input){.content = "Patate au beurre\n", .cmd = 0, .next = 0};
	t_input *headp = &head;
	// t_cmd **headpp = &headp->cmd;
	t_cmd new = (t_cmd){.content = ft_strdup("new cmd content\n"), .op = 0, .next = 0};
	t_cmd *newp = &new;

	write(1, "reached\n", 8);
	cmd_add(headp->cmd, newp);
	write(1, "reached\n", 8);

	t_cmd *current;

	current = headp->cmd;
	while (current)
	{
		ft_printf("%s\n", current->content);
		current = current->next;
	}
	return (0);
}