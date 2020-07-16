#include <unistd.h>
#include <stdio.h>

int     ft_str_is_numeric(char *str)
{
    int     i;

    i = 0;

    while (str[i])
    {
        if (str[i] >= 48 && str[i] <= 57)
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
    char    str[] = "asdfe3f4tty";
    printf("%d\n", ft_str_is_numeric(str));
    return (0);
}
