# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 16:42:35 by anjose-d          #+#    #+#              #
#    Updated: 2022/05/19 17:19:28 by anjose-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
MAIN_INCS		=	./includes
HEADER			=	$(MAIN_INCS)/push_swap.h

#COMPILER VARIABLES
CC				=	gcc
CFLAGS			=	#-Wall -Werror -Wextra

# LIBFT VARIABLES
LIBFT			=	ft
LIBFT_DIR		=	./libft
LIBFT_INC_DIR	=	$(addprefix $(LIBFT_DIR)/, includes)
LIB_LINK		=	-L$(LIBFT_DIR) -l$(LIBFT)

# SOURCES AND OBJECTS
SRCSOPS_DIR		=	ops
SRCOPS			=	px.c rrx.c rx.c sx.c
SRCS_OPS		=	$(addprefix $(SRCSOPS_DIR)/, $(SRCOPS))

SRCS_DIR		=	./srcs
SRCS			=	main.c \
					arg_check.c utils1.c \
					stack.c feed_stack.c sort_stack.c \
					short_sort.c large_sort.c \
					sort_elems.c \
					../libft/srcs/ft_dlstnew.c \
					$(SRCS_OPS) \

OBJS_DIR		=	./objs
OBJS			=	$(SRCS:.c=.o)
OBJS_PATH		=	$(addprefix $(OBJS_DIR)/, $(OBJS))
SRCS_PATH		=	$(addprefix $(SRCS_DIR)/, $(SRCS))

# ALL INCLUDES
INCS			=	-I $(MAIN_INCS) -I $(LIBFT_INC_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS_PATH)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(INCS) $(LIB_LINK) -o $@
	
all: $(NAME)
	
clean:
	rm -rf $(OBJS_DIR) debug valgrind
	make $@ -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make $@ -C $(LIBFT_DIR)

valgrind:
	$(CC) -g $(SRCS_PATH) $(INCS) $(LIB_LINK) -o $@
	valgrind -s --track-origins=yes --leak-check=full ./$@ 3 2 1 4 5 7 0 8 9 6
	
debug:
	$(CC) -g $(SRCS_PATH) $(INCS) $(LIB_LINK) -o $@
	gdb --tui ./$@ 2 1 3
	
re: fclean all

.PHONY: all clean fclean re debug valgrind


