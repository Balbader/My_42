#include <unistd.h>

void    ft_putchar(char a, char b, char c)
{
    write(1, &a, 1);
    write(1, &b, 1);
    write(1, &c, 1);
}

void    ft_print_comb(void)
{
    char    a;
    char    b;
    char    c;

    a = 48;
    while (a <= 55)
    {
        b = a + 1;
        while (b <= 56)
        {
            c = b + 1;
            while (c <= 57)
            {
                ft_putchar(a, b, c);
                if (a != 55)
                {
                    write(1, ",", 1);
                    write(1, " ", 1);
                }
                c++;
            }
            b++;
        }
        a++;
    }
}

int     main(void)
{
    ft_print_comb();
    return (0);
}













