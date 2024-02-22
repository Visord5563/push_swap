NAME = push_swap

CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

SRCM = main.c utils.c move_utils.c move_utils1.c ft_split.c linkedlist.c utilsnorminit.c sort.c

OBJM = $(SRCM:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJM)
		cc $(CFLAGS) $(OBJM) -o $@

%.o : %.c push_swap.h
		cc $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJM)

fclean : clean 
	$(RM) $(NAME) 

re : fclean all