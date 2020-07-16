#include <unistd.h>
#include <stdio.h>

char    *ft_strcapitalize(char *str)
{
    int     i;

    i =0;

    while (str[i])
    {
        if ((i == 0 && str[i] != ' ') || (str[i] != ' ' && str[i - 1] == ' '))
        {
            if (str[i] >= 'a' && str[i] <= 'z') 
            {
                str[i] = (char)(('A'-'a') + str[i] );
            }
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = (char)(str[i] + ('a' - 'A'));
        }
    }
    return (0);
}

int     main(void)
{
    char    str[] = "hello, my name is balou and I am 32 years old.";
    int     n;
    n = sizeof(str) / sizeof(str[0]);
    ft_strcapitalize(str);
    printf("%s", str); 
    return (0);
}
