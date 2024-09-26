#include "../../includes/newShell.h"

void ft_strdel(char **str){
	if (str && *str){
		free(*str);
		*str = NULL;
	}
}

