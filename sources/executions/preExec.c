#include "../../includes/newShell.h"

void	ft_isLocalCommand(t_token *t){
	if (ft_strcmp(t->arg[0], CMD_ECHO) == 0)
		t->type = CODE_ECHO;
	else if (ft_strcmp(t->arg[0], CMD_EXIT) == 0)
		t->type = CODE_EXIT;
	else if (ft_strcmp(t->arg[0], CMD_ENV) == 0)
		t->type = CODE_ENV;
	else if (ft_strcmp(t->arg[0], CMD_UNSET) == 0)
		t->type = CODE_UNSET;
	else if (ft_strcmp(t->arg[0], CMD_EXPORT) == 0)
		t->type = CODE_EXPORT;
	else if (ft_strcmp(t->arg[0], CMD_PWD) == 0)
		t->type = CODE_PWD;
	else if (ft_strcmp(t->arg[0], CMD_CD) == 0)
		t->type = CODE_CD;
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

void ft_reSizeTokenArgsExpand(t_data *d, t_token *t){
	int i = 0;
	while(t->arg[i]){
		int u = 0;
		int nSize = 0;
		int vSize = 0;
		int nbrQ = 0;
		while (t->arg[i][u]){
			if (t->arg[i][u] == SEP_SQUOTE){
				u++;
				nbrQ += 2;
				while (t->arg[i][u] != SEP_SQUOTE && t->arg[i][u])
					u++;
			}
			if (t->arg[i][u] == SEP_DQUOTE){
				u++;
				nbrQ += 2;
				while (t->arg[i][u] != SEP_DQUOTE && t->arg[i][u]){
					if (t->arg[i][u] == SEP_DOLLAR){
						nSize += ft_findVarNameLength(t->arg[i] + u);
						vSize += ft_getVarValueSize(d, t->arg[i] + u);
					}
					u++;
				}
			}
			if (t->arg[i][u] == SEP_DOLLAR){
				nSize += ft_findVarNameLength(t->arg[i] + u);
				vSize += ft_getVarValueSize(d, t->arg[i] + u);
			}
			u++;
		}
		char *newArg;
		int argSize = (ft_strlen(t->arg[i]) + vSize - nSize + 1 - nbrQ);
		if (argSize > 0)
			newArg = (char *)malloc(sizeof(char) * (argSize));
		else
			newArg = (char *)malloc(sizeof(char) * 1);
		if (!newArg)
			return ;
		printf("argSize: %d, u: %d, strlen: %d\n", argSize, u, ft_strlen(t->arg[i]));
		printf("vSize: %d, nSize: %d, nbrQ: %d\n", vSize, nSize, nbrQ);
		i++;
	}
}
