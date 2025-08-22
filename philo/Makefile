NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3 #-fsanitize=thread  

SRCS = 42_PHILO/src/main.c algho.c even_rotine.c helper.c m_rotine.c odd_rotine.c parsing.c print_utils.c store.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(OBJS) $(CFLAGS)  -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJS)
