NAME = newShell

SRC	= 	sources/main.c \

SRC +=	sources/commands/commandEcho.c \
		sources/commands/commandExit.c \
		sources/commands/commandEnv.c \
		sources/commands/commandUnset.c \
		sources/commands/commandExport.c \
		sources/commands/commandPwd.c \
		sources/commands/commandCd.c \

SRC +=	sources/utils/utilsPrints.c \
		sources/utils/utilsStrings.c \
		sources/utils/utilsSeparators.c \
		sources/utils/utilsEnv.c \

SRC +=	sources/free/freeStructData.c \
		sources/free/freeUtils.c \

SRC += 	sources/initializations/initStructData.c \

SRC += sources/parsing/parse.c \

SRC	+=	sources/executions/preExec.c \
		sources/executions/exec.c \




OBJ	= ${patsubst sources/%, objects/%, $(SRC:.c=.o)}

CC		= gcc
RM		= rm -rf
CFLAGS		= -Wall -Werror -Wextra
# CFLAGS		= 
## -fsanitize=address -g3


CLEAN_O = @echo "Object files removed!"
CLEAN_A = @echo "Executables removed!"
DONE = @echo "newShell ready to use!"

all:	$(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC)  $(CFLAGS) $(OBJ) -lreadline -o $(NAME)

objects/%.o: sources/%.c
	@mkdir -p objects
	@mkdir -p objects/commands
	@mkdir -p objects/utils
	@mkdir -p objects/free
	@mkdir -p objects/initializations
	@mkdir -p objects/parsing
	@mkdir -p objects/executions
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@${RM} objects ${OBJ}
	$(CLEAN_O)

fclean:	clean
	@${RM} ${NAME}
	$(CLEAN_A)

re: fclean all

.PHONY:	all clean fclean re obj