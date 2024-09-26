#include "../../includes/newShell.h"

void ft_exec(t_token *t, t_data *d){
	if (t->type == CODE_ECHO)
		ft_echo(t->arg);
	else if (t->type == CODE_EXIT)
		ft_exit(d);
	else if (t->type == CODE_ENV)
		ft_env(d);
	// else
	// 	ft_execve(t);
}