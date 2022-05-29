/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:41:08 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 19:00:51 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

typedef struct s_dlist	t_node;

typedef struct s_stack
{
	t_node	*node;
	t_node	*head;
	char	flag;
}				t_stack;

typedef struct s_aux
{
	char	**args_raw;
	int		*args_sorted;
	t_list	*ops;
	int		argc;
}				t_aux;

/* PRE OPERATION CHECKER */
int		arg_check(int argc, char *argv[], t_aux *args_aux);
void	feed_stack(t_stack *stack_a, t_aux *args_aux);

/* OPERATION CHECKER */
int		get_ops(t_list **ops);
int		check_valid_op(char *input);
void	checker(t_stack *a, t_aux *arg_aux);

/* UTILS1 */
int		str_spaced(char *str);
int		valid_number(char *str);
void	stack_init(t_stack *stack, char flag);
char	*ops_str(t_aux *args_aux);

/* STACK FUNCTIONS */
int		stack_push(t_stack *stack, int data);
int		stack_pop(t_stack *stack);
int		is_empty(t_node *lst);
int		is_sorted_asc(t_stack *stack);
int		has_element(t_stack *stack, int elem);

/* PUSH SWAP OPERATIONS */
void	sx(t_stack *stack);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	px(t_stack *stack_a, t_stack *stack_b, char const *op);
void	rx(t_stack *stack);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rrx(t_stack *stack);
void	rrr(t_stack *stack_a, t_stack *stack_b);

#endif