SRCS		= ft_printf.c ft_print_char.c ft_print_str.c ft_print_ptr.c ft_print_nbr.c ft_print_hex.c
OBJS		= $(SRCS:.c=.o)
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)


fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
