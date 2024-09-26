#include "../../includes/newShell.h"

char **ft_createEnv(t_data *d){
	t_env *tmp = d->env;
	int i = 0;
	while (tmp){
		i++;
		tmp = tmp->next;
	}
	char **env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!env)
		return (NULL);
	i = 0;
	tmp = d->env;
	while (tmp){
		env[i] = ft_strjoin(tmp->name, "=");
		env[i] = ft_strjoin(env[i], tmp->value);
		i++;
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}

void ft_execBin(t_token *t, t_data *d){
	char *path = ft_findPathName(t->arg[0], d);
	if (path){
		char **env = ft_createEnv(d);
		pid_t pid = fork();
		if (pid == 0){
			execve(path, t->arg, env);
			ft_putstr("Error: execve failed\n");
			exit(1);
		}
		else{
			waitpid(pid, NULL, 0);
		}
		ft_tabdel(&env);
	}
	else{
		ft_putstr("Error: command not found\n");
	}
}

void ft_exec(t_token *t, t_data *d){
	if (t->type == CODE_ECHO)
		ft_echo(t->arg);
	else if (t->type == CODE_EXIT)
		ft_exit(d);
	else if (t->type == CODE_ENV)
		ft_env(d);
	else if (t->type == CODE_UNSET)
		ft_unset(d, t->arg);
	else if (t->type == CODE_EXPORT)
		ft_export(d, t->arg);
	else if (t->type == CODE_PWD)
		ft_pwd(d);
	else if (t->type == CODE_BINCMD){
		ft_execBin(t, d);
	}
}