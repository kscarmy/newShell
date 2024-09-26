#include "../../includes/newShell.h"

void ft_structDel(t_data *d){
	if (d){
		ft_strdel(&d->ipt);
		free(d);
		d = NULL;
	}
}
