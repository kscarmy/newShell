#include "../../includes/newShell.h"

void ft_cd(t_data *d, char *path){
	if (!path || ft_strcmp(path, "~") == 0)
		path = ft_findEnvValueByName(d, "HOME");
	else if (ft_strcmp(path, "-") == 0)
		path = d->opwd;

	if (chdir(path) == -1){
		ft_putstr("Error: cd\n");
		return;
	}
	ft_strcpy(d->opwd, d->pwd);
	getcwd(d->pwd, PATH_MAX);
	ft_unsetOne(d, VAR_PWD);
	ft_unsetOne(d, VAR_OLDPWD);
	ft_addEnv(d, ft_strjoin(ft_strjoin(VAR_PWD, "="), d->pwd));
	ft_addEnv(d, ft_strjoin(ft_strjoin(VAR_OLDPWD, "="), d->opwd));
}

