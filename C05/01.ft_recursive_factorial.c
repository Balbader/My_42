#include <unistd.h>
#include <stdio.h>

int     ft_recursive_factorial(int nb)
{
    int     fact;

    if (nb == 0)
        return (1);
    else if (nb < 0)
        return (0);

    fact = nb * ft_recursive_factorial(nb - 1);
    return (fact);
}

int     main(void)
{
    printf("%d", ft_recursive_factorial(5));
    return(0);
}
