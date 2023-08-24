#include "main.h"

/**
 * print_flags - It calculates all the active flags
 * @format: String format in which to print the arguments
 * @k: takes parameter.
 * Return: Return flags
 */

int print_flags(const char *format, int *k)
{
	int s, curr_k;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_k = *k + 1; format[curr_k] != '\0'; curr_k++)
	{
		for (s = 0; FLAGS_CH[s] != '\0'; s++)
			if (format[curr_k] == FLAGS_CH[s])
			{
				flags |= FLAGS_ARR[s];
				break;
			}

		if (FLAGS_CH[s] == 0)
			break;
	}

	*k = curr_k - 1;

	return (flags);
}
