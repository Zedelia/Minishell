// printf
#include <stdio.h>

// fork
#include <unistd.h>

// pid_t type
#include <sys/types.h>

// waitpid
#include <sys/wait.h>

int main(void)
{
	int	status;
	int	w;

	// pid is the child PID for the parent, or 0 for the child
	pid_t pid = fork();
	if (pid == -1)
	{
		printf("Error\nForking failed\n");
		return (-1);
	}
	// child
	if (pid == 0)
	{
		// Code happens here
		//! Input level
		printf("I'm the child\n");
	}
	// parent
	if (pid)
	{
		//! Shell level
		w = waitpid(-1, &status, 0);
		if (w == -1)
		{
			printf("Error\nwaitpid failure\n");
		}
		printf("parent - waitpid statue %d\n", status);
		printf("I'm the parent\n");
	}
	printf("End reached\n");
	return (0);
}