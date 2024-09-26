#include "../../includes/newShell.h"

void ft_strdel(char **str){
	if (str && *str){
		free(*str);
		*str = NULL;
	}
}

void ft_tabdel(char ***tab){
	if (tab && *tab){
		int i = 0;
		while ((*tab)[i]){
			ft_strdel(&(*tab)[i]);
			i++;
		}
		free(*tab);
		*tab = NULL;
	}
}