#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int	main()
{
	char	**strings;
	char	*delimit;
	int		i;
	int		strings_len;
	
	delimit = " ";
	strings_len = strlen(*strings);
	if (!(*strings = malloc(sizeof(char*) * (strings_len + strlen(delimit)))))
		return (0);
	i = 0;
	while (strin




}

/*
int	i;
int len_src;
char dest;
char src[] = "Bonjourjgnoejngenrginringnirnrg";

i = 0;
len_src = strlen(src);
if (!(dest = (char *)malloc(sizeof(char) * (len_src + 1))))
	return (0);
	while (src[i] != '\0')
{
	dest[i] = src[i];
	i++;
}
dest[i] = '\0';

printf("%s", dest);
*/
