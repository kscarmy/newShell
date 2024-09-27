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
char *ft_findEnvValueByName(t_data *d, char *name);

/*	unset.c	*/
void ft_unset(t_data *d, char **args);
void ft_unsetOne(t_data *d, char *args);

/*	export.c	*/
void ft_export(t_data *d, char **args);
int ft_exportCheckSep(char *str);

/*	pwd.c	*/
void ft_pwd(t_data *d);

/*	cd.c	*/
void ft_cd(t_data *d, char *path);

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
char **ft_strsplit(char *str, char c);
char *ft_strjoin(char *s1, char *s2);
void ft_strcpy(char *dest, char *src);
int ft_isNotSeparator(char c);

/*	utilsSeparators.c	*/
int ft_findAllSeparators(char c);

/*	utilsEnv.c	*/
char	*ft_findEnvVarName(char *str);
char *ft_findEnvVarValue(char *str);
int ft_findVarNameLength(char *str);
int ft_getVarValueSize(t_data *d, char *str);


/*************/
/*	FREE	*/
/***********/

/*	freeUtils.c	*/
void ft_strdel(char **str);
void ft_tabdel(char ***tab);

/*	freeStructData.c	*/
void ft_structDel(t_data *d);

/*************/
/*	INIT	*/
/***********/

/*	initStructData.c	*/
void ft_initStructData(t_data *d, char **env);
void ft_initDLinkedListEnv(t_data *d);

/*	initQuotesSecurity.c	*/
int ft_chechQuotes(char *str);

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
char *ft_findPathName(char *bin, t_data *d);
void ft_reSizeTokenArgsExpand(t_data *d, t_token *t);

/*	exec.c	*/
void ft_exec(t_token *t, t_data *d);
void ft_execBin(t_token *t, t_data *d);
char **ft_createEnv(t_data *d);


#endif