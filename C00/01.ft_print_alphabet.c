#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_alphabet(void)
{
    /* Define a variable of type 'char' */
    char    c;
    
    /* initialize the variable to 97 which is the ascii decimal code for 'a' */
    c = 97;
    
    /* create a loop to define the end point of our loop. */
    /* as long as 122 is not reached, execute the code in the {} */
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
