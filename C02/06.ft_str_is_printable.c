#include <unistd.h>
#include <stdio.h>

int     ft_str_is_lowercase(char *str)
{
    int     i;

    i = 0;

    while (str[i])
    {
        if (str[i] >= 0  & str[i] <= 32)
        {
            return (0);
        }
        else
        {
            return (1);
        }
        i++;
    }
    return (1);
}

int     main(void)
{
    char    str[] = "\n";

    printf("%d\n", ft_str_is_lowercase(str));

    return (0);
}
