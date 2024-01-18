# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angnguye <angnguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/24 22:57:11 by angela            #+#    #+#              #
#    Updated: 2023/10/13 00:35:11 by angnguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
# ---------------- Nickname --------------
NAME			=	philosophers
RM				=	rm -f
CC				=	gcc

# ---------------- Color --------------
GREEN			=	\033[1;32m
BG_GREEN		=	\033[42m
LILAC			= 	\033[0;94m
ENDCOLOR		=	\033[0m

# Messages
START_TXT		=	echo "$(GREEN)Compilation of $(NAME) just started$(ENDCOLOR)"
END_COMP_TXT	=	echo "$(GREEN)Compilation is done$(ENDCOLOR)"
CLEAN_TXT		=	echo "$(GREEN)Cleaning objects$(ENDCOLOR)"
FCLEAN_TXT		=	echo "$(GREEN)Cleaning program$(ENDCOLOR)"
BS_TXT			=	echo "\n\n"
CHARG_LINE_TXT	=	echo "$(BG_GREEN)    $(ENDCOLOR)\c"

# ---------------- FLAGS --------------
CFLAGS			=	-Wall -Wextra -Werror
DEBUG			=	-fsanitize=address -g3

# ---------------- Sources -----------
SRC				=	./src/main.c \
					./src/check_arg.c \
					./src/threads_maker.c\
					./src/threads.c\
					./src/utils.c\
					./src/node_list.c\
					./src/init.c

LIB				=	./includes/philosophers.h

# ---------------- Objets -----------
OBJS			=	$(addprefix obj/, $(SRC:.c=.o))

# --------------- Regles --------------------
all: $(NAME)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@$(CHARG_LINE_TXT)

$(NAME): ${OBJS}
	@$(BS_TXT)
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lreadline
	@$(END_COMP_TXT)

rleak:
	@leaks --atExit -- ./${NAME} ${NUMTEST}

# --------------- VISUEL --------------------
start_msg:
	@$(BS_TXT)
	@tput setaf 92; cat ascii_art/cat_make; tput setaf 7
	@$(BS_TXT)

# --------------- Service nettoyage --------------------
clean:
	@$(CLEAN_TXT)
	@${RM} ${OBJS}

fclean: clean
	@$(FCLEAN_TXT)
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re rleak

# Reste de votre Makefile inchangé
