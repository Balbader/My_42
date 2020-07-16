#include <unistd.h>
#include <stdio.h>

char    *ft_strupcase(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}

int     main(void)
{
    char    str[] = "KJHASDFKJASFKLJH";
    printf("%s", ft_strupcase(str)); 
    return (0);
}
