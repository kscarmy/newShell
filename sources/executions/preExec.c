#include "../../includes/newShell.h"

void	ft_isLocalCommand(t_token *t){
	if (ft_strcmp(t->arg[0], CMD_ECHO) == 0)
		t->type = CODE_ECHO;
	else if (ft_strcmp(t->arg[0], CMD_EXIT) == 0)
		t->type = CODE_EXIT;
	else if (ft_strcmp(t->arg[0], CMD_ENV) == 0)
		t->type = CODE_ENV;
	else
		t->type = CODE_BINCMD;
}

char *ft_findPathName(char *bin, t_data *d){
	char *path = ft_findEnvValueByName(d, "PATH");
	char **pathTab = ft_strsplit(path, ':');
	int i = 0;
	while (pathTab[i]){
		char *tmp = ft_strjoin(pathTab[i], "/");
		char *tmp2 = ft_strjoin(tmp, bin);
		ft_strdel(&tmp);
		if (access(tmp2, F_OK) == 0){
			if (access(tmp2, X_OK) == 0){
				// ft_strdel(&path);
				// ft_strdel(&pathTab[i]);
				// ft_strdel(&tmp2);
				return (tmp2);
			}
			// ft_strdel(&tmp);
			// ft_strdel(&tmp2);
			// return (tmp2);
		}
		// ft_strdel(&tmp);
		ft_strdel(&tmp2);
		i++;
	}
	return (NULL);
}