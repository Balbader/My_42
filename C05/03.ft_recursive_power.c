#include <unistd.h>
#include <stdio.h>

int     ft_recursive_power(int nb, int power)
{
    int     result;

    if (power < 1)
        return (1);

    result = (nb * ft_recursive_power(nb, power - 1));

    return (result);
}

int     main(void)
{
    printf("%d", ft_recursive_power(5, 2));
    return (0);
}
