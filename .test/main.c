/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemet <anemet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 22:26:28 by anemet            #+#    #+#             */
/*   Updated: 2025/07/03 10:58:47 by anemet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
compile (after make created `libftprintf.a`):
cc main.c -L.. -lftprintf
*/

#include "../ft_printf.h"
#include <stdio.h>
#include <string.h>

// the core testing function.
// identifies the conversion type, converts the input string to the C data type
// calls `printf` and `ft_printf` for a direct comparison
void run_test(const char *format, const char *value_str)
{
	char type;
	int ret1;
	int ret2;

	// conversion type: the last char in the format string
	type = format[strlen(format) - 1];
	printf("\nFormat: [%s], Value: [%s]\n\n", format, value_str);
	printf("printf:    [");
	fflush(stdout); // Ensure "Output: [" is printed before the test

	// branching based on type
	if (strchr("di", type))
	{
		int n = atoi(value_str);
		ret1 = printf(format, n);
		printf("]\n");
		printf("ft_printf: [");
		fflush(stdout);
		ret2 = ft_printf(format, n);
		printf("]\n");
	}
	else if (strchr("uxX", type))
	{
		// Use strtoul for proper unsigned conversion from string
		unsigned int u_n = (unsigned int)strtoul(value_str, NULL, 10);
		ret1 = printf(format, u_n);
		printf("]\n");
		printf("ft_printf: [");
		fflush(stdout);
		ret2 = ft_printf(format, u_n);
		printf("]\n");
	}
	else if (type == 's')
	{
		// special handling to test a real NULL pointer
		if (strcmp(value_str, "NULL") == 0)
			value_str = NULL;
		ret1 = printf(format, value_str);
		printf("]\n");
		printf("ft_printf: [");
		fflush(stdout);
		ret2 = ft_printf(format, value_str);
		printf("]\n");
	}
	else if (type == 'c')
	{
		ret1 = printf(format, value_str[0]);
		printf("]\n");
		printf("ft_printf: [");
		fflush(stdout);
		ret2 = ft_printf(format, value_str[0]);
		printf("]\n");
	}
	else if (type == 'p')
	{
		if (strcmp(value_str, "NULL") == 0)
		{
			ret1 = printf(format, NULL);
			printf("]\n");
			printf("ft_printf: [");
			fflush(stdout);
			ret2 = ft_printf(format, NULL);
			printf("]\n");
		}
		else
		{
			uintptr_t uip = (uintptr_t)strtoul(value_str, NULL, 16);
			ret1 = printf(format, uip);
			printf("]\n");
			printf("ft_printf: [");
			fflush(stdout);
			ret2 = ft_printf(format, uip);
			printf("]\n");
		}
	}
	else if (type == '%')
	{
		ret1 = printf("%s", format);
		printf("]\n");
		printf("ft_printf: [");
		fflush(stdout);
		ret2 = ft_printf("%s", format);
		printf("]\n");
	}
	else
	{
		printf("Unsupported format specifier '%c'", type);
		ret1 = 0;
		ret2 = 0;
	}

	if (ret1 != ret2)
	{
		printf("printf return:    %d\n", ret1);
		printf("ft_printf return: %d\n", ret2);
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: ./a.out \"%%<format>\" \"<value>\"\n");
		printf("Example: ./a.out \"%%-10.5d\" \"-42\"\n");
		printf("Example: ./a.out \"%%s\" \"hello\"\n");
		printf("Example: ./a.out \"%%s\" \"NULL\" (to test a NULL pointer)\n");
		printf("Example: ./a.out \"%%#x\" \"1234\"\n");
		return (1);
	}
	if (argv[1][0] != '%')
	{
		printf("Error: First argument must be a format string starting with '%%'.\n");
		return (1);
	}
	run_test(argv[1], argv[2]);
	return (0);
}

/*

compile (after make created `libftprintf.a`):
cc main.c -L.. -lftprintf

# Test a simple integer
./a.out "%d" "42"

# Test bonus flags
./a.out "%-10.5d" "-123"

# Test a string
./a.out "%s" "hello world"

# Test a NULL string pointer
./a.out "%s" "NULL"

# Test hexadecimal with bonus flags
./a.out "%#012X" "98765"

# Test a pointer
./a.out "%p" "any_value"

# Test a NULL pointer
./a.out "%p" "NULL"

*/
