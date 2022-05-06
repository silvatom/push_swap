/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:42:46 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/06 01:59:07 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

#define TRUE 1
#define FALSE 0

# ifndef INT_MAX
#  define INT_MAX __INT_MAX__
# endif
# ifndef INT_MIN
#  define INT_MIN (-__INT_MAX__ -1)
# endif

typedef struct s_dlist t_node;

typedef struct s_stack
{
	t_node	*node;
	t_node	*head;
}				t_stack;



int	arg_check(int argc, char *argv[], char ***args);

/* UTILS */
int	str_spaced(char *str);
int	valid_number(char *str);

/* STACK FUNCTIONS */
int	stack_push(t_stack *stack, int data);
int	stack_pop(t_stack *stack);
int	isEmpty(t_node *lst);

/* PUSH SWAP OPERATIONS */
void	sx(t_stack *stack);
void	px(t_stack *stack_a, t_stack *stack_b, char const *op);
void	rx(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrx(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif