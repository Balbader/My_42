#include <unistd.h>
#include <stdio.h>

#define nel 256

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_hex(char c)
{
    char    str[] = "0123456789abcdef";

    ft_putchar(str[c / 16]);
    ft_putchar(str[c % 16]);
}

void    ft_putstr_non_printable(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 0 && str[i] <= 32)
        {
            ft_putchar(92);
            ft_print_hex(str[i]);
        }
        else
            ft_putchar(str[i]);
        i++; 
    }
}

int     main(void)
{
    char    arr[] = "hello world";
    ft_putstr_non_printable(arr);
    return (0);
}
