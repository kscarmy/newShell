#include "../../includes/newShell.h"

void ft_exit(t_data *d){
	// printf("Dans ft_exit :\n");
	// printf("Au revoir !\n");
	ft_structDel(d);
	exit(0);
}