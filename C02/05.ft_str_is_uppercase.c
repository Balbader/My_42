#include <unistd.h>
#include <stdio.h>

int     ft_str_is_lowercase(char *str)
{
    int     i;

    i = 0;

    while (str[i])
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            return (1);
        }
        else
        {
            return (0);
        }
        i++;
    }
    return (1);
}

int     main(void)
{
    char    str[] = "90ljadsfLKAJSDFLKJ";

    printf("%d\n", ft_str_is_lowercase(str));

    return (0);
}
