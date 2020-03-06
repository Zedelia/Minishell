/* just run this :
gcc -Wall -Wextra -Werror src/howto/signal+fork.c&& ./a.out
*/

// printf
#include <stdio.h>

// fork
#include <unistd.h>

// pid_t type
#include <sys/types.h>

// waitpid
#include <sys/wait.h>

// signal
#include <signal.h>

// exit
#include <stdlib.h>

void sigint(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	if (signum == 2)
		exit(0);
}

//! WIP (aka doesn't work at all)
void sigterm(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	if (signum == 2)
		exit(0);
}

void sigquit(int signum)
{
	printf("\n%s ~ Signal %d caught, coming out...", __func__, signum);
	if (signum == 3)
		exit(0);
}


/*
Ctrl+C tells the terminal to send a SIGINT to the current foreground process,
which by default translates into terminating the application.
CtrlD tells the terminal that it should register a EOF on standard input,
which bash interprets as a desire to exit.

Short version is
ctrl+C interrupt + go back to a clear shell prompt
ctrl+D EOF, ends properly what you're doing AKA multiline
ctrl+\ exit with a QUIT Signal
*/

/* How to SIGNAL with no fork */
/*
int main(void)
{
	signal(SIGINT, sighandler);
	while (1)
	{
		printf("My parent should kill me but I don't have parents so just play with me with ctrl+c, ctrl+d or ctrl+\\ !\n");
		sleep(1);
	}
}
*/

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
		// init the signal, so it knows where to send the SIGINT
		signal(SIGINT, sigint);
		signal(SIGTERM, sigterm);
		signal(SIGQUIT, sigquit);

		// Code happens here
		//! Input level
		while (1)
		{
			printf("I'm the child ! Kill me please ! Ctrl+ C, D or \\ !\n");
			sleep(1);
		}
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