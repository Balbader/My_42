#include <unistd.h>

void    ft_putstr(char *str)
{
    int     i;

    i = 0;

    while (str[i])
    {
        write(1, str, 1);
        str++;
    }
}

int main(int argc, char *argv[]) 
{
    int     i;

    i = 1;

    while (argv[i])
    {
        ft_putstr(argv[i]);
        write(1, "\n", 1);
        i++;
    }
    return (0);
}
