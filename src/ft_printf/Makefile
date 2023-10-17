#	****************************************************************************	#
#																																																																														#
#																																																									:::						::::::::				#
#				Makefile																																											:+:						:+:				:+:				#
#																																																					+:+	+:+									+:+						#
#				By:	angnguye	<angnguye@student.42.fr>										+#+		+:+							+#+									#
#																																																	+#+#+#+#+#+			+#+												#
#				Created:	2022/12/09	17:33:37	by	angnguye										#+#				#+#														#
#				Updated:	2022/12/16	03:35:12	by	angnguye									###			########.fr								#
#																																																																														#
#	****************************************************************************	#

SRCS		=	ft_printf.c	\
				s_c_p_d_i.c	\
				u_x_X.c



OBJS		=	$(SRCS:.c=.o)
CC			=	gcc -M
CFLAGS		=	#-Wall	-Wextra	#-Werror
NAME		=	libftprintf.a
INC			=	-I./
all:	$(NAME)
$(NAME):	$(OBJS)
				ar	rcs	$(NAME)	$(OBJS)
%.o	:	%.c
	$(CC)	$(CFLAGS)	$(INC)	-c	$<	-o	$@

clean:
				rm	-f	$(OBJS)

fclean:	clean
				rm	-f	$(NAME)

re:		fclean	$(NAME)

norm:
			norminette	$(SRCS)

.PHONY:	all	clean	fclean	re	norm
