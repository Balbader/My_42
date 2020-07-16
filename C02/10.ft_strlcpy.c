#include <unistd.h>
#include <stdio.h>

unsigned int    ft_strlcpy(char *dest, char *src, unsigned int size)
{
    unsigned int    i;
    unsigned int    length;

    i = 0;
    while ((src[i]) && (i + 1) < size)
    {
        dest[i] = src[i];
        i++;
    }
    if (size > 0)
    {
        dest[i] = '\0';
    }
    length = 0;
    while (src[length])
    {
        length++;
    }
    return (length);
}

int             main(void)
{
    char    text1[] = "Hello World.";
    char    text2[101];
    int     i;

    printf("%u", ft_strlcpy(text2, text1, i));
    return (0);
}
