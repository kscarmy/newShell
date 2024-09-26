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