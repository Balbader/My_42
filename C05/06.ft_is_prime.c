#include <unistd.h>
#include <stdio.h>

int     ft_is_prime(int nb)
{
    int     i;

    i = 2;
    
    while (i <= nb / 2)
    {
        if (nb % i == 0)
            return (0);
        i++;
    }
    if (nb == 1 || nb == 0)
        return (0);
    else 
        return (1);
}

int     main(void)
{
    printf("%d", ft_is_prime(55));
    return (0);
}
