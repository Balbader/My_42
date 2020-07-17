#include <unistd.h>
#include <stdio.h>

#define nel 101

char    *ft_strcat(char *dest, char *src)
{
    char    full_str[nel];
    int     i;
    int     j;

    i = 0;
    j = 0;

    while (src[i] != '\0')
    {
        full_str[j] = src[i];
        i++;
        j++;
    }
    i = 0;
    while (dest[i] != '\0')
    {
        full_str[j] = dest[i];
        i++;
        j++;
    }
    full_str[j] = '\0';
    return (full_str);
}

int     main(void)
{
    char    str1[nel] = "Hello, ";
    char    str2[] = "my name is Basil.";

    printf("%s", ft_strcat(str2, str1));

    return (0);
}
