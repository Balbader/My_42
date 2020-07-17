#include <unistd.h>
#include <stdio.h>

int     ft_strcmp(char *s1, char *s2)
{
    int		i;

	i = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
    {
		i++;
    }
	return (s1[i] - s2[i]);
}

int     main(void)
{
    char    str1[] = "abasilou";
    char    str2[] = "mimi";

    printf("%d", ft_strcmp(str1, str2));

    return (0);
}
