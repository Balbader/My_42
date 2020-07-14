#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_alphabet(void)
{
    char    c;
  
    c = 97;
    while (c <= 122)
    {
        ft_putchar(c);  // print char c
        c++;            // increment c by 1
    } 
}

int     main(void)
{
    ft_print_alphabet();
    return (0);
}
