NAME = philo
#
SRCS =	main.c print_messages.c simulation.c ft_atoi.c is_digit.c \
		init_forks.c init_threads.c clear_all.c print_micro.c \
		inspection.c ft_usleep.c
#
HEADER = philosophers.h
OBJ = $(patsubst %.c, %.o, $(SRCS))
#
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
#
#CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -fsanitize=thread -g
#
.PHONY : all clean fclean re bonus
#
all : $(NAME)
#
$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $@
#
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
#
clean :
	rm -f $(OBJ)
#
fclean : clean
	$(RM) $(NAME)
#
re : fclean all