#include "../../includes/newShell.h"

char	*ft_findEnvVarName(char *str){
	int i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (ft_strndup(str, i));
}

char *ft_findEnvVarValue(char *str){
	int i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (ft_strdup(str + i + 1));
}