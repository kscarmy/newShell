#include "../../includes/newShell.h"

int ft_strcmp(const char *s1, const char *s2){
	while (*s1 && *s2 && *s1 == *s2){
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int ft_strncmp(const char *s1, const char *s2, size_t n){
	while (n && *s1 && *s2 && *s1 == *s2){
		s1++;
		s2++;
		n--;
	}
	if (n == 0){
		return (0);
	}
	return (*s1 - *s2);
}

char *ft_strndup(const char *s, size_t n){
	char *str;
	size_t i = 0;
	if (!(str = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (i < n){
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char *ft_strdup(const char *s){
	char *str;
	size_t i = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i]){
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int ft_strlen(const char *str){
	int i = 0;
	if (!str)
		return (0);
	while (str[i]){
		i++;
	}
	return (i);
}

char **ft_strsplit(char *str, char c){
	int i = 0;
	int j = 0;
	int k = 0;
	char **tab;
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i]){
		if (str[i] == c){
			tab[j] = ft_strndup(&str[k], i - k);
			j++;
			k = i + 1;
		}
		i++;
	}
	tab[j] = ft_strndup(&str[k], i - k);
	tab[j + 1] = NULL;
	return (tab);
}

char *ft_strjoin(char *s1, char *s2){
	char *str;
	int i = 0;
	int j = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i]){
		str[i] = s1[i];
		i++;
	}
	while (s2[j]){
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void ft_strcpy(char *dest, char *src){
	int i = 0;
	while (src[i]){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int ft_isNotSeparator(char c){
	if (c == SEP_SPACE || c == SEP_TAB || c == SEP_NEWLINE)
		return (0);
	else if (c == SEP_SEMICOLON || c == SEP_PIPE || c == SEP_AND)
		return (0);
	else if (c == SEP_INPUT)
		return (0);
	else if (c == SEP_OUTPUT)
		return (0);
	else if (c == SEP_PARENTHESIS_OPEN)
		return (0);
	else if (c == SEP_PARENTHESIS_CLOSE || c == SEP_SQUOTE || c == SEP_DQUOTE)
		return (0);
	else if (c == SEP_DOLLAR)
		return (0);
	return (1);
}

char *ft_strcat(char *dest, char *src){
	int i = 0;
	int j = 0;
	while (dest[i]){
		i++;
	}
	while (src[j]){
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void ft_bzero(void *s, size_t n){
	size_t i = 0;
	while (i < n){
		((char *)s)[i] = 0;
		i++;
	}
}