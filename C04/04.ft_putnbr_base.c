#include <unistd.h>
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     ft_strlen(char *str)
{
    int     i;

    i = 0;

    while (*str)
    {
        i++;
    }
    return (i);
}

/* Check if the string contains any errors */
int     errors_check(char *str)
{
    int     i;
    int     j;
    int     length;

    i = 0;
    length = ft_strlen(str);

    /* check if string is empty or size 1 */
    if (length == 0 || length == 1)
        return (0);

    while (*str)
    {
        j = i + 1;
        /* check if the string contains any non printable character or + or - sign */
        if (*str == '+' || *str == '-' || *str >= 127 || *str <= 32)
            return (0);

        /* check if the string contians the same character twice */
        while (str[j])
        {
            if (*str == str[j])
                return(0);
            j++;
        }
        i++;
    }
    return (1);
}

void    string_conversion(long int num, char *str)
{
    long int    length;

    length = ft_strlen(str);

    if (num >= length)
        string_conversion(num / length, str);

    ft_putchar(str[num % length]);
}

void    ft_putnbr_base(int nbr, char *base)
{
    long int    i;

    i = nbr;

    if (errors_check(base))
    {
        /* handle negative numbers */
        if (nbr < 0)
        {
            ft_putchar('-');
            i = -i;
        }
        string_conversion(i, base);
    }
}

int     main(void)
{
    char    str[] =  "---+--+7fz0111100245";
    int     i;

    i = 0;

    ft_putnbr_base(i, str);

    return (0);
}
