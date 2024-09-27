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
	int i = 1;
	// printf("ft_findVarNameLength str: <%s>\n", str);
	while (str[i] && ft_isNotSeparator(str[i])){
		// printf("ft_findVarNameLength str[%d]: <%c>\n", i, str[i]);
		i++;
	}
	// printf("ft_findVarNameLength str[%d]: <%c>\n", i, str[i]);
	// if (str[i - 1] == SEP_DQUOTE)
	// 	i--;
	return (i);
}

int ft_getVarValueSize(t_data *d, char *str){
	int nSize = ft_findVarNameLength(str);
	char *name = ft_strndup(str, nSize);
	return (ft_strlen(ft_findEnvValueByName(d, &name[1])));
}

char *ft_getVarValue(t_data *d, char *str){
	// printf("ft_getVarValue str: <%s>\n", str);
	int nSize = ft_findVarNameLength(str);
	char *name = ft_strndup(str, nSize);
	// printf("ft_getVarValue name: <%s> nSize %d\n", name, nSize);
	return (ft_findEnvValueByName(d, &name[1]));
}
