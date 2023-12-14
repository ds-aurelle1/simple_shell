#include <stdio.h>
#include <unistd.h>
#include "shell.h"

/**
 * main - PID
 * Return: 0
 */

int main(void)
{
	pid_t my_pid;

	my_pid = getpid();
	printf("hola %u\n", my_pid);
	my_pid = getppid();
	printf("sure %u\n", my_pid);
	return (0);
}
