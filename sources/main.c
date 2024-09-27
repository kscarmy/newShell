#include "../includes/newShell.h"


int ft_size_of_first_word(char *str){
	int i = 0;
	while (str[i] && str[i] != ' '){
		i++;
	}
	return (i);
}

int	 ft_find_cmd_in_str(char *str){
	if (ft_strncmp(str, CMD_ECHO, ft_size_of_first_word(CMD_ECHO)) == 0){
		return (CODE_ECHO);
	}
	if (ft_strncmp(str, CMD_EXIT, ft_size_of_first_word(CMD_EXIT)) == 0){
		return (CODE_EXIT);
	}
	if (ft_strncmp(str, CMD_ENV, ft_size_of_first_word(CMD_ENV)) == 0){
		return (CODE_ENV);
	}
	return (-1);
}

int	main(int argc, char **argv, char **env){
	argc = 0;
	argv = NULL;
	(void)argc;
	(void)argv;
	t_data *d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (1);
	ft_initStructData(d, env);

    while (1) {
        // Afficher l'invite de commande
        d->ipt = readline("shell> ");
        if (!d->ipt) {
            break; // Sortir si readline échoue (CTRL+D)
        }
		if (ft_strlen(d->ipt) == 0){
			ft_strdel(&d->ipt);
			continue;
		}
        // Ajouter l'entrée à l'historique
        add_history(d->ipt);

		if (ft_chechQuotes(d->ipt)){
			ft_putstr("Error: quotes\n");
			ft_strdel(&d->ipt);
			continue;
		}

        // Traiter l'entrée

		ft_parseOneToken(d);	// parsing


		ft_isLocalCommand(d->tok);	// pre-execution
		ft_exec(d->tok, d);			// execution

        // Libérer la mémoire allouée pour l'entrée
		ft_strdel(&d->ipt);
    }
	ft_structDel(d);
	return (0);
}

