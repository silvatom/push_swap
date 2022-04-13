# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 16:42:35 by anjose-d          #+#    #+#              #
#    Updated: 2022/04/13 15:10:37 by anjose-d         ###   ########.fr        #
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
SRCS_DIR		=	./srcs
SRCS			=	main.c

OBJS_DIR		=	./objs
OBJS			=	$(SRCS:.c=.o)
OBJS_PATH		=	$(addprefix $(OBJS_DIR)/, $(OBJS))

# ALL INCLUDES
INCS			=	-I $(MAIN_INCS) -I $(LIBFT_INC_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c  $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS_PATH)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $< $(INCS) $(LIB_LINK)  -o $@
	
all: $(NAME)
	
clean:
	rm -rf $(OBJS_DIR)
	make $@ -C $(LIBFT_DIR)

fclean: $(clean)
	rm $(NAME)
	make $@ -C $(LIBFT_DIR)
	
re: $(fclean) $(all)

.PHONY: all clean fclean re


