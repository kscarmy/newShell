#include "../../includes/newShell.h"

char *ft_findEnvValueByName(t_data *d, char *name){
	t_env *tmp = d->env;
	while (tmp){
		if (ft_strcmp(tmp->name, name) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void ft_addEnv(t_data *d, char *str){
	t_env *new = (t_env *)malloc(sizeof(t_env));
	if (!new)
		return ;
	new->name = ft_findEnvVarName(str);
	new->value = ft_findEnvVarValue(str);
	new->prev = NULL;	// became the first element so there is no previous element (oui j'ecris en anglais et en francais)
	if (d->env != NULL){
		d->env->prev = new;	// add address of this element to the next element so it can be accessed
		new->next = d->env;	// add address of the next element to this element so it can be accessed
	}
	d->env = new;	// add new element to the beginning of the list
}

void ft_env(t_data *d){
	t_env *tmp = d->env; // Un pointeur temporaire pour parcourir la liste, c'est comme un iterator en C++ ;)
	while (tmp){
		ft_putstr(tmp->name);
		ft_putstr("=");
		ft_putstr(tmp->value);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
