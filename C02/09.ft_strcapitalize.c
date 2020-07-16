#include <unistd.h>
#include <stdio.h>

char    *ft_strcapitalize(char *str)
{
    int     i;
    int     cap;

    i = 0;
    cap = 1;

    while (str[i])
    {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
	    {
            if (cap && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			else if (!cap && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
			cap = 0;
		}
        else
            cap = 1;
		i++;
    }
    return (str);
}

int     main(void)
{
    char    str[] = "hello, my name is balou and I am 32 years old.";
    printf("%s", ft_strcapitalize(str)); 
    return (0);
}
