#include <unistd.h>
#include <stdio.h>

int     ft_str_is_alpha(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] > 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
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
    char    arr[] = "////////";

    printf("%d\n", ft_str_is_alpha(arr));

    return (0);
}
