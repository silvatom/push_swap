/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:36:49 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 18:40:39 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find the best elem in stack A to the element from B */
static void	elem_from_a(t_stack *a, t_stack *b, t_aux *arg_aux, t_sort *aux_a);

/* find the spot (or element) the B elem needs to have on top of stack A */
static int	find_elem(t_stack *stack, t_aux *args_aux, int b_elem, int side);

void	send_back(t_stack *a, t_stack *b, t_aux *arg_aux)
{
	t_sort	elem_a_aux;
	t_sort	elem_b_aux;
	t_sort	temp_a;
	t_sort	temp_b;
	int		i;

	sort_aux_init(&temp_a);
	sort_aux_init(&temp_b);
	sort_aux_init(&elem_a_aux);
	sort_aux_init(&elem_b_aux);
	i = -1;
	while (++i < ft_dlstsize(b->head))
	{
		elem_from_a(a, b, arg_aux, &temp_a);
		temp_b.elem = b->node->elem;
		temp_b.idx = find_pos_elem(b, temp_b.elem);
		find_mv(a, &temp_a, 'a');
		find_mv(b, &temp_b, 'b');
		best_mv(&elem_a_aux, &elem_b_aux, &temp_a, &temp_b);
		b->node = b->node->next;
	}
	b->node = b->head;
	arg_aux->a_aux = &elem_a_aux;
	arg_aux->b_aux = &elem_b_aux;
	do_best_mv(a, b, arg_aux);
}

static int	find_elem(t_stack *stack, t_aux *args_aux, int elem, int side)
{
	int	i;

	i = 0;
	while (args_aux->args_sorted[i] != elem)
		i++;
	if (side > 0 || ft_dlstsize(stack->head) == 2)
	{
		while (!has_element(stack, args_aux->args_sorted[i])
			&& i < args_aux->argc)
			i++;
	}
	else
	{
		while (!has_element(stack, args_aux->args_sorted[i])
			&& i < args_aux->argc)
			i--;
	}
	return (args_aux->args_sorted[i]);
}

static void	elem_from_a(t_stack *a, t_stack *b, t_aux *arg_aux, t_sort *aux_a)
{
	int	a_elem;
	int	b_elem;
	int	idx_elem_a;
	int	scnd_biggest_from_a;

	b_elem = b->node->elem;
	a_elem = 0;
	scnd_biggest_from_a = scnd_biggest_elem(a);
	if (b_elem > scnd_biggest_from_a)
	{
		a_elem = biggest_elem_stack(a);
		idx_elem_a = find_pos_elem(a, a_elem);
	}
	else
	{
		a_elem = find_elem(a, arg_aux, b_elem, UP);
		idx_elem_a = find_pos_elem(a, a_elem);
	}
	aux_a->elem = a_elem;
	aux_a->idx = idx_elem_a;
}
