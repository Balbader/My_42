#include <unistd.h>
#include <stdio.h>

#define nel 101

char    *ft_strncat(char *dest, char *src, unsigned int n)
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
    while (i < n)
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
    char    str1[nel] = "Hello";
    char    str2[] = " World.";
    int     add_char;

    add_char = 5;

    printf("%s", ft_strncat(str2, str1, add_char));
    return (0);
}
