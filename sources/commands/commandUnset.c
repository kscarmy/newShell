#include "../../includes/newShell.h"

void ft_unsetOne(t_data *d, char *args){
	t_env *tmp = d->env;
	while (tmp){
		if (ft_strcmp(tmp->name, args) == 0){
			if (tmp->prev)
				tmp->prev->next = tmp->next;
			if (tmp->next)
				tmp->next->prev = tmp->prev;
			if (tmp == d->env)
				d->env = tmp->next;
			ft_strdel(&tmp->name);
			ft_strdel(&tmp->value);
			free(tmp);
			break ;
		}
		tmp = tmp->next;
	}
}

void	ft_unset(t_data *d, char **args){
	int i = 1;
	while(args[i]){
		ft_unsetOne(d, args[i]);
		i++;
	}
}
