#include "../../includes/newShell.h"

int ft_numberOfArgs(char *str){
	int i = 0;
	int count = 0;
	while (str[i]){
		while (str[i] == SEP_SPACE && str[i])
			i++;
		if (str[i] != SEP_SPACE && str[i])
			count++;
		if (str[i] == SEP_SQUOTE){
			i++;
			while (str[i] != SEP_SQUOTE && str[i])
				i++;
		}
		if (str[i] == SEP_DQUOTE){
			i++;
			while (str[i] != SEP_DQUOTE && str[i])
				i++;
		}
		while (str[i] != SEP_SPACE && str[i])
			i++;
	}
	return (count);
}

int ft_argLength(char *str){
	int i = 0;
	while (str[i] && str[i] != SEP_SPACE){
		if (str[i] == SEP_SQUOTE){
			i++;
			while (str[i] != SEP_SQUOTE && str[i])
				i++;
		}
		if (str[i] == SEP_DQUOTE){
			i++;
			while (str[i] != SEP_DQUOTE && str[i])
				i++;
		}
		i++;
	}
	printf("len: %d\n", i);
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
		if (d->ipt[i] == '\0')
			break;
		len = ft_argLength(d->ipt + i);
		d->tok->arg[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (!d->tok->arg[j])
			return ;
		while (d->ipt[i] != SEP_SPACE && d->ipt[i]){
			if (d->ipt[i] == SEP_SQUOTE){
				i++;
				while (d->ipt[i] != SEP_SQUOTE && d->ipt[i]){
					d->tok->arg[j][k] = d->ipt[i];
					i++;
					k++;
				}
				i++;
			}
			else if (d->ipt[i] == SEP_DQUOTE){
				i++;
				while (d->ipt[i] != SEP_DQUOTE && d->ipt[i]){
					d->tok->arg[j][k] = d->ipt[i];
					i++;
					k++;
				}
				i++;
			}
			else {
				d->tok->arg[j][k] = d->ipt[i];
				i++;
				k++;
			}
		}
		// else {
		// 	// i++;
		// 	while (d->ipt[i] != SEP_SPACE && d->ipt[i]){
		// 		d->tok->arg[j][k] = d->ipt[i];
		// 		i++;
		// 		k++;
		// 	}
		// 	i++;
		// }
		d->tok->arg[j][k] = '\0';
		k = 0;
		j++;
		printf("B arg[i] s<%s> c<%c> d%d\n", &d->ipt[i], d->ipt[i], i);
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
	if (!tmp->arg)
		return ;
	tmp->arg[ft_numberOfArgs(d->ipt)] = NULL;
	d->tok = tmp;
	ft_mallocArg(d);
}

void ft_parseOneToken(t_data *d){
	ft_mallocToken(d);
	ft_printToken(d->tok);
	printf("nbr args: %d\n", ft_numberOfArgs(d->ipt));
}
