#include <unistd.h>
#include <stdio.h>

int     ft_atoi(char *str)
{
    int     res;
    int     negative;
    int     i;

    negative = 0;
    res = 0;
    i = 0;
    
    /* if str starts with an arbitrary amount of white-space chatacter */
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		str++;
    
    /* if str is followed by an arbitrary amount of + and - signs */
	while (str[i] == '-' || str[i] == '+')
        /* change int sign based on the number of - and if that number is even or odd */
		if (str[i++] == '-')
			negative = 1 - negative;
	/* if str is followed by number of the base 10 */
	while (str[i] >= '0' && str[i] <= '9')
    	{
		res = res * 10 + str[i] - 48;
        	str++;
    	}
    	return (negative * (res * -1));
}

int     main(void)
{
    char    str[] = "  ---+--+13425Hel9890lo World.";
    printf("%d", ft_atoi(str));
    return (0);
}
