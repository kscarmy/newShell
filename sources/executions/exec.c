#include "../../includes/newShell.h"

void ft_exec(t_token *t, t_data *d){
	if (t->type == CODE_ECHO)
		ft_echo(t->arg);
	else if (t->type == CODE_EXIT)
		ft_exit(d);
	else if (t->type == CODE_ENV)
		ft_env(d);
	else if (t->type == CODE_BINCMD){
		char *path = ft_findPathName(t->arg[0], d);
		if (path){
			pid_t pid = fork();
			if (pid == 0){
				execve(path, t->arg, d->mEnv);
				ft_putstr("Error: execve failed\n");
				exit(1);
			}
			else{
				waitpid(pid, NULL, 0);
			}
		}
		else{
			ft_putstr("Error: command not found\n");
		}
	}
}