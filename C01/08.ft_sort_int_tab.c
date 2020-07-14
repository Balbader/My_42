#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *first_nbr, int *second_nbr)
{
    int     temp;

    temp = *first_nbr;
    *first_nbr = *second_nbr;
    *second_nbr = temp;
}

void    ft_sort_int_tab(int *tab, int size)
{
    int     i;
    int     j;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (tab[i] < tab[j])
            {
                ft_swap(&tab[i], &tab[j]);
            }
            j++;
        }
        i++;
    }

}

int     main(void)
{
    int     arr[5] = {7, 2, 89, 33, 1};
    int     size;

    size = 5;
    printf("%d ", ft_sort_int_tab(arr, size));

    return (0);
}












