#include <unistd.h>
#include <stdio.h>

int     ft_iterative_factorial(int nb)
{
    int     n;
    int     fact;

    n = 1;
    fact = 1;

    if (nb < 0)
        return (0);
    else if (nb == 0)
        return (1);
    while (n <= nb)
    {
        fact = fact * n;
        n++;
    }
    return (fact);
}

int     main(void)
{
    printf("%d", ft_iterative_factorial(-8));
    return (0);
}

