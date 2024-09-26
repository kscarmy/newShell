#include "../../includes/newShell.h"

int ft_numberOfArgs(char *str){
	int i = 0;
	int count = 0;
	while (str[i]){
		while (str[i] == ' ' && str[i])
			i++;
		if (str[i] != ' ' && str[i])
			count++;
		while (str[i] != ' ' && str[i])
			i++;
	}
	return (count);
}

int ft_argLength(char *str){
	int i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

void ft_mallocArgs(t_data *d){
}

void ft_mallocToken(t_data *d){
	t_token *tmp = (t_token *)malloc(sizeof(t_token));
	if (!tmp)
		return ;
	tmp->n = NULL;	// TEMPORAIRE
	tmp->p = NULL; // TEMPORAIRE
	tmp->arg = (char **)malloc(sizeof(char *) * (ft_numberOfArgs(d->ipt) + 1));
	if (!tmp->arg)
		return ;
	d->tok = tmp;
	// ft_mallocArgs(d); // A FAIRE
}

void ft_parseOneToken(t_data *d){
	printf("nbr args : %d\n", ft_numberOfArgs(d->ipt));

}