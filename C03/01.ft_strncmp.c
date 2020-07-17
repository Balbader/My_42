#include <unistd.h>
#include <stdio.h>

int     ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int     i;

    i = 0;

    while(s1[i] <= n && s2[i] <= n)
    {
        i++;
    }
    return (s1[i] - s2[i]);
}

int     main(void)
{
    char    str1[] = "Hello, my name is basil.";
    char    str2[] = "It's a beautiful day.";
    int     cmp_char;

    cmp_char = 6;

    printf("%d", ft_strncmp(str1, str2, cmp_char));
    return (0);
}

