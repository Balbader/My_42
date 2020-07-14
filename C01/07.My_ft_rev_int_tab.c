#include <unistd.h>
#include <stdio.h>

#define MAX_SIZE 101

void    ft_rev_int_tab(int *tab, int size)
{
    int     *tab_fin = (tab + size - 1);

    while (tab <= tab_fin)
    {
        printf("%d, ", *tab);
        tab++;
    }
}

int     main(void)
{
    int tab[MAX_SIZE];
    int size;
    int *left = tab;  // Pointer to arr[0]
    int *right;


    // Input size of array
    printf("Enter size of array: ");
    scanf("%d", &size);

    right = &tab[size - 1];  // Pointer to arr[size - 1]

    /*
     * Input elements in array
     */
    printf("Enter elements in array: ");
    while(left <= right)
    {
        scanf("%d", left++);
    }


    printf("\nArray before reverse: ");
    ft_rev_int_tab(tab, size);


    // Make sure that left points to arr[0]
    left = tab;


    // Loop to reverse array
    while(left < right) 
    {
        /*
         * Swap element from left of array to right of array.
         */
        *left    ^= *right;
        *right   ^= *left;
        *left    ^= *right;

        // Increment left array pointer and decrement right array pointer
        left++;
        right--;
    }


    printf("\nArray after reverse: ");
    ft_rev_int_tab(tab, size);


    return 0;
}
