#include "../../includes/newShell.h"

int ft_numberOfArgs(char *str){
	int i = 0;
	int count = 0;
	while (str[i]){
		while (str[i] == SEP_SPACE && str[i])
			i++;
		if (str[i] != SEP_SPACE && str[i])
			count++;
		while (str[i] != SEP_SPACE && str[i])
			i++;
	}
	return (count);
}

int ft_argLength(char *str){
	int i = 0;
	while (str[i] && str[i] != SEP_SPACE)
		i++;
	return (i);
}

void ft_mallocArg(t_data *d){ // every space in d->ipt delimitate args for d->tok->arg
	int i = 0;
	int j = 0;
	int k = 0;
	int len = 0;
	while (d->ipt[i]){
		while (d->ipt[i] == SEP_SPACE && d->ipt[i])
			i++;
		len = ft_argLength(d->ipt + i);
		d->tok->arg[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!d->tok->arg[j])
			return ;
		while (d->ipt[i] != SEP_SPACE && d->ipt[i]){
			d->tok->arg[j][k] = d->ipt[i];
			i++;
			k++;
		}
		d->tok->arg[j][k] = '\0';
		k = 0;
		j++;
	}
	d->tok->arg[j] = NULL;
}

void ft_mallocToken(t_data *d){
	t_token *tmp = (t_token *)malloc(sizeof(t_token));
	if (!tmp)
		return ;
	tmp->n = NULL;	// TEMPORAIRE
	tmp->p = NULL; // TEMPORAIRE
	tmp->arg = (char **)malloc(sizeof(char *) * (ft_numberOfArgs(d->ipt) + 1));
	tmp->arg[ft_numberOfArgs(d->ipt)] = NULL;
	if (!tmp->arg)
		return ;
	d->tok = tmp;
	ft_mallocArg(d);
}

void ft_parseOneToken(t_data *d){
	printf("Number of args: %d\n", ft_numberOfArgs(d->ipt));
	ft_mallocToken(d);
	ft_printToken(d->tok);
}