#ifndef STRUCT_H
# define STRUCT_H

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
	char *pwd; // present working directory
	char *opwd; // old present working directory
	char *ipt; // input
	char **mEnv; // main env
	t_env *env; // linked list env
	t_token *tok; // linked list token
}	t_data;


#endif