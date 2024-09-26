#include "../../includes/newShell.h"

void ft_echo(char **arg){
	int i = 1;
	int backN = 0;
	if (!arg[i]){
		ft_putchar('\n');
		return ;
	}
	else if (ft_strcmp(arg[i], "-n") == 0)
		backN = 1;
	while (arg[i + backN]){
		ft_putstr(arg[i + backN]);
		if (arg[i + backN + 1])
			ft_putchar(' ');
		i++;
	}
	if (!backN)
		ft_putchar('\n');
}