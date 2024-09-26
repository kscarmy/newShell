#ifndef LOCAL_LIB_H
# define LOCAL_LIB_H

/*	main.c	*/
typedef struct s_env
{
	char *name;
	char *value;
	struct s_env *next;
	struct s_env *prev;
}	t_env;

typedef struct s_token
{
	int type; // separator, local command, binary command
	int sep;	
	char *pn; // path name, for execve or local command
	char **arg; // arguments for execve
	struct s_token *n; // next
	struct s_token *p; // previous
}	t_token;

typedef struct s_data
{
	char *ipt; // input
	char **mEnv; // main env
	t_env *env; // linked list env
	t_token *tok; // linked list token
}	t_data;

/*****************/
/*	COMMANDS	*/
/***************/

/*	echo.c	*/
void ft_echo(char *str);

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


#endif