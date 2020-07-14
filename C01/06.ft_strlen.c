#include <unistd.h>
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_strlen(char *str)
{
    int     nbr_of_char;
    int     i;

    nbr_of_char = '0';
    i = 0;

    while (str[i])
    {
        i++;
        nbr_of_char++;
    }
    ft_putchar (nbr_of_char); // This function call is for testing purposes.
}

int     main(void)
{
    char text[] = "hello";

    ft_strlen(text);

    return (0);

}
