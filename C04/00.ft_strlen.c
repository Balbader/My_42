#include <unistd.h>
#include <stdio.h>

int     ft_strlen(char *str)
{
    int     char_tot;
    int     i;
    
    char_tot = 0;
    i = 0;

    while (str[i])
    {
        char_tot = i;
        i++;
    }
    return (char_tot);
}

int     main(void)
{
    char    str[] = "Hello World.";
    printf("%d", ft_strlen(str));
    return (0);
}
