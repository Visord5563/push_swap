# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: saharchi <saharchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 12:31:34 by saharchi          #+#    #+#              #
#    Updated: 2024/02/24 12:31:35 by saharchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker

CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

SRCM = main.c utils.c move_utils.c move_utils1.c ft_split.c linkedlist.c utilsnorm.c sort.c utilsnorm1.c

SRCB = 	bonus/checker.c bonus/ft_split_.c bonus/get_next_line.c bonus/linkedlist_.c \
		bonus/move_utils_.c bonus/move_utils1_.c bonus/utils_.c bonus/utilsnorm_.c bonus/utilsnorm1_.c

OBJM = $(SRCM:%.c=%.o)

OBJB = $(SRCB:%.c=%.o)

$(NAME) : $(OBJM)
		cc $(CFLAGS) $(OBJM) -o $(NAME)
all : $(NAME)

bonus: $(BNAME)


$(BNAME) : $(OBJB)
		cc $(CFLAGS) $(OBJB) -o $(BNAME)

%.o : %.c push_swap.h
		cc $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/checker.h
		cc $(CFLAGS) -c $< -o $@


clean :
	$(RM) $(OBJM) $(OBJB)

fclean : clean 
	$(RM) $(NAME) $(BNAME)

re : fclean all