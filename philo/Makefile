NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

SRCS = PHILO_42/src/main.c PHILO_42/pars/parsing.c
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
