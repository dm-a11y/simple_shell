#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int x, y, i, j, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (is_delim(str[x], d))
			x++;
		i = 0;
		while (!is_delim(str[x + i], d) && str[x + i])
			i++;
		s[y] = malloc((i + 1) * sizeof(char));
		if (!s[y])
		{
			for (i = 0; i < y; i++)
				free(s[i]);
			free(s);
			return (NULL);
		}
		for (j = 0; j < i; j++)
			s[y][j] = str[x++];
		s[y][j] = 0;
	}
	s[y] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int x, y, i, j, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (x = 0, y = 0; y < numwords; y++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		i = 0;
		while (str[x + i] != d && str[x + i] && str[x + i] != d)
			i++;
		s[y] = malloc((i + 1) * sizeof(char));
		if (!s[y])
		{
			for (i = 0; i < y; i++)
				free(s[i]);
			free(s);
			return (NULL);
		}
		for (j = 0; j < i; j++)
			s[y][j] = str[x++];
		s[y][j] = 0;
	}
	s[y] = NULL;
	return (s);
}
