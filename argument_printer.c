#include "main.h"

/**
 * argument_print - Argument printed based on its type
 * @fmt: String format into which print the arguments.
 * @list: Arguments list to be printed
 * @indx: Index
 * @buffer: argument print to buffer array
 * @flags: It calculates active flags
 * @width: print width.
 * @precision: The specification of the precision
 * @size: It specify size
 * Return: Return 1 or 2;
 */

int argument_print(const char *fmt, int *indx, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int k, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_chars}, {'s', print_str}, {'%', print_perc},
		{'i', print_integer}, {'d', print_integer}, {'b', print_bin},
		{'u', print_unsig}, {'o', print_octal}, {'x', print_hex},
		{'X', print_hex_upper}, {'p', print_pointer}, {'S', print_non_printables},
		{'r', print_rev}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (k = 0; fmt_types[k].fmt != '\0'; k++)
		if (fmt[*indx] == fmt_types[k].fmt)
			return (fmt_types[k].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[k].fmt == '\0')
	{
		if (fmt[*indx] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*indx - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*indx);
			while (fmt[*indx] != ' ' && fmt[*indx] != '%')
				--(*indx);
			if (fmt[*indx] == ' ')
				--(*indx);
			return (1);
		}
		unknow_len += write(1, &fmt[*indx], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
