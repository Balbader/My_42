#include <unistd.h>
#include <stdio.h>

#define nel 101

char    *ft_strstr(char *str, char *to_find)
{
    int     i;
    int     j;

    i = 0;

    while (str[i])
    {
        j = 0;
        while (to_find[j] == str[i + j])
        {
            if (to_find[j + 1] == '\0')
                return (str + i);
            j++;
        }       
        i++;
    }
    if (to_find[i] == '\0')
        return (NULL);
    return (0);
}

int     main(void)
{
    char    str[] = "Hello, how are you?";
    char    to_find[] = "how";
    
    printf("%s", ft_strstr(str, to_find));
    return (0);
}
