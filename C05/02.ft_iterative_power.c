#include <unistd.h>
#include <stdio.h>

int     ft_iterative_power(int nb, int power)
{
    int     result;

    result = 1;
    
    if (power < 0)
        return(0);
    while (power > 0)
    {
        result = result * nb;
        power--;
    }
    return (result);
}

int     main(void)
{
    printf("%d", ft_iterative_power(5, 2));
    return (0);
}
