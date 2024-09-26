#include "../../includes/newShell.h"

int ft_findAllSingleSeparators(char c){
	if (c == SEP_SPACE)
		return (CODE_SEP_SPACE);
	if (c == SEP_TAB)
		return (CODE_SEP_TAB);
	if (c == SEP_NEWLINE)
		return (CODE_SEP_NEWLINE);
	if (c == SEP_SEMICOLON)
		return (CODE_SEP_SEMICOLON);
	if (c == SEP_PIPE)
		return (CODE_SEP_PIPE);
	if (c == SEP_AND)
		return (CODE_SEP_AND);
	if (c == SEP_INPUT)
		return (CODE_SEP_INPUT);
	if (c == SEP_OUTPUT)
		return (CODE_SEP_OUTPUT);
	if (c == SEP_PARENTHESIS_OPEN)
		return (CODE_SEP_PARENTHESIS_OPEN);
	if (c == SEP_PARENTHESIS_CLOSE)
		return (CODE_SEP_PARENTHESIS_CLOSE);
	return (0);
}

