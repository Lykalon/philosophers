NAME = philo_bonus
#
SRCS = 	checks.c main.c ft_atoi.c ft_usleep.c init.c is_digit.c \
		simulation.c
#
HEADER = philosophers.h
OBJ = $(patsubst %.c, %.o, $(SRCS))
OBJ_B = $(patsubst %.c, %.o, $(SRCS_B))
#
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(HEADER) #-fsanitize=thread -g
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
$(NAME_B) : $(OBJ_B) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ_B) -o $@
#
clean :
	rm -f $(OBJ) $(OBJ_B)
#
fclean : clean
	$(RM) $(NAME)
#
re : fclean all