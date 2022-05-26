/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:42:46 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/26 20:50:28 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

# define CHUNKS 2
# define UP 1
# define DOWN -1

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

typedef struct s_sort_aux
{
	int		ck_end1;
	int		ck_end2;
	int		elem2mv;
	int		idx;
	char	*mv;
	int		mv_qtd;
	int		has_elem;
}				t_sort_aux;

typedef struct s_sort
{
	int		elem;
	int		idx;
	int		mv_qtd;
	char	*mv;
}				t_sort;

/* ARG CHECKING */
int		arg_check(int argc, char *argv[], t_aux *args_aux);

/* FEED STACK */
void	feed_stack(t_stack *stack_a, t_aux *args_aux);

/* UTILS1 */
int		str_spaced(char *str);
int		valid_number(char *str);
void	stack_init(t_stack *stack, char flag);
char	*ops_str(t_aux *args_aux);

/* UTILS2 */
int		biggest_elem_stack(t_stack *stack);
int		smallest_elem_stack(t_stack *stack);
int		scnd_biggest_elem(t_stack *stack);
int		scnd_smallest_elem(t_stack *stack);

/* SORTING */
void	sort_elems(t_stack *stack, t_aux *arg_aux);
void	sort_stack(t_stack *stack_a, t_aux *args_aux);
void	short_sort(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux);
void	large_sort(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux);

/* SORT UTILS */
void	find_spot(t_stack *stack, t_aux *args_aux, int a_elem, int side);
void	find_best_mv(t_stack *stack, t_aux *args_aux, t_sort *sort_aux, char c);
void	biggest2top(t_stack *stack, t_aux *args_aux, char *op);
/* tirar depois daqui pois era pra ser static */
void	bring_elem2top(t_stack *stack, t_aux *args_aux, int elem, char *op);
int		find_pos_elem(t_stack *stack, int elem);

/* STACK FUNCTIONS */
int		stack_push(t_stack *stack, int data);
int		stack_pop(t_stack *stack);
int		is_empty(t_node *lst);
int		is_sorted_desc(t_stack *stack);
int		has_element(t_stack *stack, int elem);

/* PUSH SWAP OPERATIONS */
void	sx(t_stack *stack, t_list **ops, const char *op);
void	ss(t_stack *stack_a, t_stack *stack_b, t_list **ops);
void	px(t_stack *stack_a, t_stack *stack_b, t_list **ops, char const *op);
void	rx(t_stack *stack, t_list **ops, const char *op);
void	rr(t_stack *stack_a, t_stack *stack_b, t_list **ops);
void	rrx(t_stack *stack, t_list **ops, const char *op);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_list **ops);

void	best_mv(t_stack *a, t_stack *b, t_aux *arg_aux, t_sort_aux *sort_aux);
int		find_pos_elem(t_stack *stack, int elem);

#endif