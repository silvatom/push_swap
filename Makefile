# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 16:42:35 by anjose-d          #+#    #+#              #
#    Updated: 2022/05/28 01:56:17 by anjose-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
NAME_BNS		=	checker
MAIN_INCS		=	./includes
HEADER			=	$(MAIN_INCS)/push_swap.h
HEADER_BNS		=	$(MAIN_INCS)/push_swap_bonus.h

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
					arg_check.c utils1.c utils2.c utils_sort.c \
					find_best_mv.c do_best_mv.c \
					stack.c feed_stack.c sort_stack.c sort_utils.c \
					short_sort.c large_sort.c \
					sort_elems.c \
					$(SRCS_OPS) \

OBJS_DIR		=	./objs
OBJS			=	$(SRCS:.c=.o)
OBJS_PATH		=	$(addprefix $(OBJS_DIR)/, $(OBJS))
SRCS_PATH		=	$(addprefix $(SRCS_DIR)/, $(SRCS))

# BONUS
SRCS_DIR_BNS	=	./srcs_bonus
SRCS_BNS		=	main_bonus.c \
					arg_check_bonus.c \
					utils1_bonus.c utils2_bonus.c \
					stack_bonus.c feed_stack_bonus.c \
					$(SRCS_BNS_OPS) \
					# find_best_mv_bonus.c do_best_mv_bonus.c \
					# sort_stack.c sort_utils.c \
					# short_sort.c large_sort.c \
					# sort_elems.c \
					
SRCSOPS_BNS_DIR	=	ops
SRCOPS_BNS		=	px_bonus.c rrx_bonus.c rx_bonus.c sx_bonus.c
SRCS_BNS_OPS	=	$(addprefix $(SRCSOPS_BNS_DIR)/, $(SRCOPS_BNS))				

OBJS_BNS_DIR	=	./objs_bonus
OBJS_BNS		=	$(SRCS_BNS:.c=.o)
OBJS_BNS_PATH	=	$(addprefix $(OBJS_BNS_DIR)/, $(OBJS_BNS))
SRCS_BNS_PATH	=	$(addprefix $(SRCS_DIR_BNS)/, $(SRCS_BNS))



# ALL INCLUDES
INCS			=	-I $(MAIN_INCS) -I $(LIBFT_INC_DIR)

# MANDATORY
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# BONUS
$(OBJS_BNS_DIR)/%.o: $(SRCS_DIR_BNS)/%.c $(HEADER_BNS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS_PATH)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(INCS) $(LIB_LINK) -o $@

bonus: $(NAME_BNS)

$(NAME_BNS): $(OBJS_BNS_PATH)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $^ $(INCS) $(LIB_LINK) -o $@

clean:
	rm -rf $(OBJS_DIR) debug valgrind 
	rm -rf $(OBJS_BNS_DIR) debug_bonus valgrind_bonus
	make $@ -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BNS)
	make $@ -C $(LIBFT_DIR)

valgrind:
	$(CC) -g $(SRCS_PATH) $(INCS) $(LIB_LINK) -o $@
	valgrind -s --track-origins=yes --leak-check=full ./$@ 3 2 1 4 5 7 0 8 9 6
	
debug:
	$(CC) -g $(SRCS_PATH) $(INCS) $(LIB_LINK) -o $@
	gdb --tui ./$@ 3 2 1 4 5 7 0 8 9 6

debug_bonus:
	$(CC) -g $(SRCS_BNS_PATH) $(INCS) $(LIB_LINK) -o $@
	gdb --tui ./$@ 2 1 3

valgrind_bonus:
	$(CC) -g $(SRCS_BNS_PATH) $(INCS) $(LIB_LINK) -o $@
	valgrind -s --track-origins=yes --leak-check=full ./$@ 2 1 3
	
re: fclean all

.PHONY: all bonus clean fclean re debug valgrind


