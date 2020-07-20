#include <unistd.h>
#include <stdio.h>

int     ft_sqrt(int nb)
{
    double  err;
    int     sq;
    
    err = 0.00001;
    sq = nb;

    if (nb == 1)
        return (1);
    if (nb == 0)
        return (0);
    while ((sq - nb / sq) > err)
        sq = (sq + nb / sq) / 2;
    return (sq);
}

int     main(void)
{
    printf("%d", ft_sqrt(5));
    return (0);
}
