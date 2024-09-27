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
		// ft_strdel(&t->arg[i]);
		char *tmp;
		int argSize = (ft_strlen(t->arg[i]) + vSize - nSize + 1 - nbrQ);
		if (argSize > 0)
			tmp = (char *)malloc(sizeof(char) * (argSize));
		else
			tmp = (char *)malloc(sizeof(char) * 1);
		if (!tmp)
			return ;
		ft_bzero(tmp, argSize);
		// printf("argSize: %d, u: %d, strlen: %d\n", argSize, u, ft_strlen(t->arg[i]));
		// printf("vSize: %d, nSize: %d, nbrQ: %d\n", vSize, nSize, nbrQ);

		u = 0;
		nSize = 0;
		vSize = 0;
		nbrQ = 0;
		int j = 0;
		while (t->arg[i][u]){
			// ft_putstr("A\n");
			if (t->arg[i][u] == SEP_SQUOTE){
				u++;
				nbrQ += 2;
				while (t->arg[i][u] != SEP_SQUOTE && t->arg[i][u]){
					if (t->arg[i][u] == SEP_SQUOTE){
						u++;
						break;
					}
					tmp[j] = t->arg[i][u];
					j++;
					u++;
				}
			}
			// ft_putstr("A\n");
			if (t->arg[i][u] == SEP_DQUOTE){
				u++;
				nbrQ += 2;
				// ft_putstr("AB\n");
				while (t->arg[i][u] != SEP_DQUOTE && t->arg[i][u]){
					// ft_putstr("AC\n");
					if (t->arg[i][u] == SEP_DQUOTE){
						u++;
						break;
					}
					// ft_putstr("AD\n");
					if (t->arg[i][u] == SEP_DOLLAR){
						nSize += ft_findVarNameLength(t->arg[i] + u);
						// printf("nSize: %d, str[u] <%s>\n", nSize, &t->arg[i][u]);
						// ft_putstr("C1\n");
						// vSize += ft_getVarValueSize(d, t->arg[i] + u);
						// printf("VarVal <%s>\n", ft_getVarValue(d, t->arg[i] + u));
						// printf("tmp: <%s>\n", tmp + j);
						// printf("AD str <%s>\n", t->arg[i] + u);
						char *tmp2 = ft_getVarValue(d, t->arg[i] + u);
						// printf("AD tmp2 <%s>\n", tmp2);
						// printf("tmp2: <%s>\n", tmp2);
						ft_strcat(tmp, tmp2);
						// printf("tmp: <%s>\n", tmp);
						// ft_putstr("C2\n");
						j+= ft_strlen(tmp2);
						u += nSize;
						nSize = 0;
						// printf("nSize: %d, str[u] <%s>\n", nSize, &t->arg[i][u]);
						// continue;
					}
					// ft_putstr("AE\n");
					if (t->arg[i][u] == SEP_DQUOTE){
						u++;
						break;
					}
					// ft_putstr("AF\n");
					if (t->arg[i][u] != SEP_DOLLAR){
						tmp[j] = t->arg[i][u];
						j++;
						u++;
					}


				}
			}
			else if (t->arg[i][u] == SEP_DOLLAR){
				// ft_putstr("C\n");
				nSize += ft_findVarNameLength(t->arg[i] + u);
				// ft_putstr("C1\n");
				// vSize += ft_getVarValueSize(d, t->arg[i] + u);
				// printf("VarVal <%s>\n", ft_getVarValue(d, t->arg[i] + u));
				// printf("tmp: <%s>\n", tmp + j);
				char *tmp2 = ft_getVarValue(d, t->arg[i] + u);
				// printf("tmp2: <%s>\n", tmp2);
				ft_strcat(tmp, tmp2);
				// printf("tmp: <%s>\n", tmp);
				// ft_putstr("C2\n");
				j+= ft_strlen(tmp2);
				u += nSize;
				nSize = 0;
			}
			else if (t->arg[i][u] != SEP_DQUOTE && t->arg[i][u] != SEP_DOLLAR){
				// ft_putstr("D\n");
				if (j == argSize - 1)
					tmp[j] = '\0';
				else
					tmp[j] = t->arg[i][u];
				j++;
				u++;
			}
		}
		// printf("tmp: <%s>\n", tmp);
		ft_strdel(&t->arg[i]);
		t->arg[i] = tmp;
		// printf("t->arg[%d]: <%s>\n", i, t->arg[i]);
		i++;
	}
}


