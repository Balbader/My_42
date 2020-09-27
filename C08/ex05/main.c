#include "ft_stock_str.h"

int main(int ac, char **av)
{
	t_stock_str *tab;

	(void)ac;
	tab = ft_strs_to_tab(ac, av);
	ft_show_tab(tab);
	return (0);
}

