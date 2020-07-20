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

int     ft_find_next_prime(int nb)
{
    int		i;

	i = nb;
	while (i >= nb)
	{
		if (ft_is_prime(i))
			return (i);
		i++;
	}
	return (nb);
}

int     main(void)
{
    printf("%d", ft_find_next_prime(6));
    return (0);
}
