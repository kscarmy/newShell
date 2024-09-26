#include "../../includes/newShell.h"

void ft_putchar(char c){
	write(1, &c, 1);
}

void ft_putstr(char *str){
	int i = 0;
	while (str[i]){
		ft_putchar(str[i]);
		i++;
	}
}

void ft_printData(t_data *d){
	ft_putstr("d->ipt : '");
	ft_putstr(d->ipt);
	ft_putstr("'\n");
}