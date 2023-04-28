#include "main.h"

int print_char(va_list arg)
{
        putchar(va_arg(arg, int));
        return (1);
}

int print_str(va_list arg)
{
        int i;
        char *str = va_arg(arg, char *);

        if (!str)
            str = "(null)";

        for (i = 0; str[i]; i++)
            putchar(str[i]);

        return (i);
}

int print_mod(va_list arg)
{
	(void)arg;

	putchar('%');
	return (1);
}

int print_int(va_list arg)
{
	int number = va_arg(arg, int), len = 0;
	unsigned int digits = number;

	if (number < 0)
	{
		putchar('-');
		digits *= -1;
		len++;
	}
	len += int_helper(digits);
	return (len);
}

int int_helper(unsigned int value)
{
    int len;

    if (value == 0)
    {
        return (0);
    }
    len = (1 + int_helper(value / 10));
    putchar(value % 10 + '0');
    return (len);
}
