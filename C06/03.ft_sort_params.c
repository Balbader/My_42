#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int     i;
    
    i = 0;

    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}


int     ft_strcmp(char *a, char *b)
{
    while (*a && *a == *b)
    {
        a++;
        b++;
    }
    return (*a - *b);
}

void    ft_print_params(int nbr, char *str[])
{
    int     i;

    i = 1;
    while (i < nbr)
    {
        ft_putstr(str[i]);
        ft_putchar('\n');
        i++;
    }
}

int     main(int argc, char *argv[])
{
    int     i;
    int     j;
    char    *str;

    i = 1;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (ft_strcmp(argv[i], argv[j]) > 0)
            {
                str = argv[j];
                argv[j] = argv[i];
                argv[i] = str;
            }
            j++;
        }
        i++;
    }
    ft_print_params(argc, argv);
    return (0);
}
