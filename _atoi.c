#include "shell.h"

/**
 * interactive - checks if shell is in interactive mode
 * so that it returns true
 * @info: struct info
 * Return: if it is in interactive mode(1) but (0) otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - cconfirms whether char is a delim
 * @c: character to be checked
 * @delim: string delimeter
 * Return: 1 (true), 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - inspects alphabetic char
 * @c: char to be inputted
 * Return: 1 (when c is alphabetic), 0 otherwise
 */

int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

/**
 * _atoi - changes str to int value
 * @s: str to convert
 * Return: 0 when there is no numbers in string,
 * or number converted otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	i = 0;
	while (s[i] != '\0' && flag != 2)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
		i++;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
