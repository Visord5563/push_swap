NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCM = main.c push_swap_util.c 

OBJM = $(SRCM:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJM)
		cc $(OBJM) -o $@

%.o : %.c push_swap.h
		cc $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJM)

fclean : clean 
	$(RM) $(NAME) 

re : fclean all