#include <unistd.h>

void    ft_putnbr(int nb)
{
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = - nb;
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
    }
    nb = nb % 10 + '0';
    write(1, &nb, 1);
}

int     main(void)
{
    ft_putnbr(42);
    return (0);
}
