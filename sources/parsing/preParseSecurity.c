#include "../../includes/newShell.h"

int ft_chechQuotes(char *str){
	int sq = 0;
	int dq = 0;
	int i = 0;

	while (str[i]){
		if (str[i] == SEP_SQUOTE && sq == 0 && dq == 0) // on croise un premier quote simple
			sq++;
		else if (str[i] == SEP_SQUOTE && sq == 1 && dq == 0) // on croise un deuxieme quote simple
			sq--;

		if (str[i] == SEP_DQUOTE && dq == 0 && sq == 0) // on croise un premier quote double
			dq++;
		else if (str[i] == SEP_DQUOTE && dq == 1 && sq == 0) // on croise un deuxieme quote double
			dq--;
		i++;
	}
	printf("sq = %d, dq = %d\n", sq, dq);
	if (sq == 0 && dq == 0)
		return (0);
	return (1);
}