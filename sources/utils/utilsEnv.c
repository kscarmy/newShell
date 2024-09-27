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

int ft_findVarNameLength(char *str){
	int i = 0;
	while (str[i] && ft_isNotSeparator(str[i])){
		i++;
	}
	return (i);
}

int ft_getVarValueSize(t_data *d, char *str){
	int nSize = ft_findVarNameLength(str);
	char *name = ft_strndup(str, nSize);
	return (ft_strlen(ft_findEnvValueByName(d, &name[1])));
}