#include <unistd.h>
#include <stdio.h>

#define nel 101

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

unsigned int   ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int    i;
    unsigned int    j;
    unsigned int    dest_length;

    i = 0;
    if (size == 0)
        return (ft_strlen(src));
    while (dest[i])
        i++;
    j = 0;
    dest_length = i;
    while (src[i] && j + i < size - 1)
    {
        dest[i + j] = src[j];
        j++;
    }
    if (j < size)
        dest[i + j] = '\0';
    if (size < dest_length)
        return (ft_strlen(src) + size);
    return (dest_length + ft_strlen(src));
}

int     main(void)
{
    char    first[nel] = "This is ";
    char    last[nel] = "a potentially long string";
    int     size = 16;

    printf("%d", ft_strlcat(first, last, size));
    return(0);
}
