#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int     x;
    x = *a;
    *a = *b;
    *b = x;
}
void    ft_rev_int_tab(int *tab, int size)
{
    int     i;
    int     j;    

    i = 0;
    j = size - 1;

    while (i < j)
    {
        ft_swap(&tab[i], &tab[j]);
        i++;
        j--;
    }
}
/* Need to understand how to print the result to the screen
 *
int     main(void)
{
    int     size;
    int     *tab;
    
    size = 9;
    *tab = size;

    ft_rev_int_tab(tab, size);
    printf("%d ", size);
    return (0);
}
*/ 
