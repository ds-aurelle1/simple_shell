#include "shell.h"

/**
 * bfree - this function frees
 * @ptr: pointer to free
 * Return: 1 for success, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
