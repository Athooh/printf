#include "main.h"

/**
 * print_width - It calculates the width for printing
 * @format: String format in which to be printed in the arguments.
 * @k: List of all arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Return width.
 */

int print_width(const char *format, int *k, va_list list)
{
	int curr_k;
	int width = 0;

	for (curr_k = *k + 1; format[curr_k] != '\0'; curr_k++)
	{
		if (is_dgt(format[curr_k]))
		{
			width *= 10;
			width += format[curr_k] - '0';
		}
		else if (format[curr_k] == '*')
		{
			curr_k++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*k = curr_k - 1;

	return (width);
}
