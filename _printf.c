#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - it the printf function
 * @fmt: used for format.
 * Return: returns printed characters.
 */
int _printf(const char *fmt, ...)
{
	int k, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_indx = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (fmt == NULL)
		return (-1);

	va_start(list, fmt);

	for (k = 0; fmt && fmt[k] != '\0'; k++)
	{
		if (fmt[k] != '%')
		{
			buffer[buff_indx++] = fmt[k];
			if (buff_indx == BUFF_SIZE)
				print_buffer(buffer, &buff_indx);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_indx);
			flags = print_flags(fmt, &k);
			width = print_width(fmt, &k, list);
			precision = print_precision(fmt, &k, list);
			size = print_size(fmt, &k);
			++k;
			printed = argument_print(fmt, &k, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_indx);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints buffer contents if it exist
 * @buffer: character arrays
 * @buff_indx: array Index to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_indx)
{
	if (*buff_indx > 0)
		write(1, &buffer[0], *buff_indx);

	*buff_indx = 0;
}
