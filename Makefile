NAME = 
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

SRCS = /PHILO_42/src/main.c 
OBJS = $(SRCS:.c=.o)
LIB = ./ft_libft/libft.a

all  : $(NAME)


$(LIB):
	$(MAKE) -C ft_libft/

$(NAME): $(OBJS) $(LIB)
	$(CC) $(OBJS) $(CFLAGS) $(LIB) -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ft_libft/

fclean: clean
	$(MAKE) fclean -C ft_libft/ 
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re

.SECONDARY: $(OBJS)