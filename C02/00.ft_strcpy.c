#include <unistd.h>
#include <stdio.h> /* The <stdio.h> is used for testing purposes only. */

#define nel 101

char    *ft_strcpy(char *dest, char *src)
{
    int     i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    return dest;   
}

/*
int     main(void) 
{
    char    arr1[] = "Hello World.";
    char    arr2[nel];

    printf("%s " , ft_strcpy(arr2, arr1));
    return (0);
}
*/ 
