#include "../../includes/newShell.h"

int ft_exportCheckSep(char *str){
	int i = 1;
	while (str[i]){
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void ft_export(t_data *d, char **args){
	int i = 1;
	while (args[i]){
		if (ft_exportCheckSep(args[i])){
			ft_unsetOne(d, ft_findEnvVarName(args[i]));
			ft_addEnv(d, args[i]);
		}
		i++;
	}
}
