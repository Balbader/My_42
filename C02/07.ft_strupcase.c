#include <unistd.h>
#include <stdio.h>

char    *ft_strupcase(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] = str[i] - 32;
        }
        i++;
    }
    return (str);
}

int     main(void)
{
    char    str[] = "lkjdkjaslkfj";
    printf("%s", ft_strupcase(str)); 
    return (0);
}
