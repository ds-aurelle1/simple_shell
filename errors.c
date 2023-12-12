#include "shell.h"

/**
 * _eputs - writes the string inputted
 * @str: string to print
 * Return: void
 */
void _eputs(char *str)
{
	int i;

	if (!str)
		return;
	for (i = 0; str[i] != '\0'; i++)
	{
		_eputchar(str[i]);
	}
}

/**
 * _eputchar - prints character to the STDERR
 * @c: character to be printed
 * Return: 1 (successful)
 * -1 (error)
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH)
	{
		write(2, buf, i);
		i = 0;
	}
	if (i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - prints character c to a specific file descriptor
 * @c: character to be printed
 * @fd: file descriptor to print to
 * Return: 1 (successful)
 * -1 (error)
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd - writes string inputted
 * @str: string to print
 * @fd: file descriptor to print to
 * Return: the number of chars
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
