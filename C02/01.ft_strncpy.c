#include <unistd.h>
#include <stdio.h>

char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
    int     i;

    i = 0;

    while (src[i] && i < n)
    {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

int     main(void)
{
    char    arr1[] = "Hello World.";
    char    arr2[101];

    printf("%s", ft_strncpy(arr2, arr1, 3));

    return (0); 
}
