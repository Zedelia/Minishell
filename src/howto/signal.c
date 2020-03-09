// printf
#include <stdio.h>

// signal
#include <signal.h>

// sleep
#include <unistd.h>

void sighandler(int signum)
{
	printf("Signal %d caught, coming out...", signum);
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
int main(void)
{
	signal(SIGINT, sighandler);
	while (1)
	{
		printf("My parent should kill me but I don't have parents so just play with me with ctrl+c, ctrl+d or ctrl+\\ !\n");
		sleep(1);
	}
}
