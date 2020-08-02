#include <unistd.h>
#include <stdio.h>

void    ft_rev_int_tab(int *tab, int size)
{
    int     *end_tab = (tab + size - 1);
    
    while (tab <= end_tab)
    {
        printf("%d ", *end_tab);
        end_tab--;
    }
}

int     main(void)
{
    int     arr[] = {1, 2, 3, 4, 5};
    int     size;

    size = 5;

    ft_rev_int_tab(arr, size);
    return (0);
}
