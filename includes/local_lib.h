#ifndef LOCAL_LIB_H
# define LOCAL_LIB_H

/*	main.c	*/

/*****************/
/*	COMMANDS	*/
/***************/

/*	echo.c	*/
void ft_echo(char **arg);

/*	exit.c	*/
void ft_exit(t_data *d);

/*	env.c	*/
void ft_env(t_data *d);
void ft_addEnv(t_data *d, char *str);

/*************/
/*	UTILS	*/
/***********/

/*	print.c	*/
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_printData(t_data *d);
void ft_printToken(t_token *t);

/*	strings.c	*/
int ft_strcmp(const char *s1, const char *s2);
int ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_strndup(const char *s, size_t n);
char *ft_strdup(const char *s);
int ft_strlen(const char *str);

/*	utilsSeparators.c	*/
int ft_findAllSeparators(char c);

/*	utilsEnv.c	*/
char	*ft_findEnvVarName(char *str);
char *ft_findEnvVarValue(char *str);


/*************/
/*	FREE	*/
/***********/

/*	freeUtils.c	*/
void ft_strdel(char **str);

/*	freeStructData.c	*/
void ft_structDel(t_data *d);

/*************/
/*	INIT	*/
/***********/

/*	initStructData.c	*/
void ft_initStructData(t_data *d, char **env);
void ft_initDLinkedListEnv(t_data *d);

/*************/
/*	PARSING	*/
/***********/

/*	parse.c	*/
int ft_numberOfArgs(char *str);
void ft_parseOneToken(t_data *d);
void ft_mallocToken(t_data *d);
void ft_mallocArg(t_data *d);


/*****************/
/*	EXECUTIONS	*/
/***************/

/*	preExec.c	*/
void ft_isLocalCommand(t_token *t);

/*	exec.c	*/
void ft_exec(t_token *t, t_data *d);


#endif