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