NAME = 	so_long

SRCS =	so_long.c set_map.c components_checker.c \
		draw.c ft_draw.c moves.c moves2.c \
		ft_itoa.c ft_putstr.c ft_strncmp.c ft_strrchr.c \
		get_next_line.c get_next_line_utils.c

OBJS =	$(SRCS:.c=.o)
RM =	rm -f

all:	$(NAME)

%.o:	%.c
		$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re