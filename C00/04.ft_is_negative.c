#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_is_negative(int n)
{
    char    P;
    char    N;
    
    P = 'P';
    N = 'N';

    if (n >= 0)
    {
        ft_putchar(P);
    }
    else
    {
        ft_putchar(N);
    }
}

int     main(void)
{
    ft_is_negative(6);
    ft_is_negative(-3);
    return (0);
}
