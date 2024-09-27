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

void ft_printToken(t_token *t){
	int i = 0;
	ft_putstr("t->arg : ");
	while (t->arg[i]){
		ft_putstr("<");
		ft_putstr(t->arg[i]);
		ft_putstr("> ");
		i++;
	}
	ft_putstr("\n");
}
