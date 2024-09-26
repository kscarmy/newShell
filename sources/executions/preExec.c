#include "../../includes/newShell.h"

void	ft_isLocalCommand(t_token *t){
	if (ft_strcmp(t->arg[0], CMD_ECHO) == 0)
		t->type = CODE_ECHO;
	else if (ft_strcmp(t->arg[0], CMD_EXIT) == 0)
		t->type = CODE_EXIT;
	else if (ft_strcmp(t->arg[0], CMD_ENV) == 0)
		t->type = CODE_ENV;
}

