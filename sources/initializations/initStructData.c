#include "../../includes/newShell.h"


void ft_initDLinkedListEnv(t_data *d){
	int i = 0;
	while (d->mEnv[i])
		i++;
	i--;
	while (d->mEnv[i]){
		ft_addEnv(d, d->mEnv[i]);
		i--;
	}
}

void ft_initStructData(t_data *d, char **env){
	d->ipt = NULL;
	d->mEnv = env;
	d->env = NULL;
	ft_initDLinkedListEnv(d);
}

