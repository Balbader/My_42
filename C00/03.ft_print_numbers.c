#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_numbers(void)
{
    char    c;
    
    c = 48;
    while(c <= 57)
    {
        ft_putchar(c);
        c++;
    }
}

int     main(void)
{
    ft_print_numbers();
    return (0);
}
