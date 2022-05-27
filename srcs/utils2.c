/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:43:30 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/27 01:33:30 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_elem_stack(t_stack *stack)
{
	int	biggest;

	biggest = stack->head->elem;
	while (stack->node)
	{
		if (biggest < stack->node->elem)
			biggest = stack->node->elem;
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (biggest);
}

int	smallest_elem_stack(t_stack *stack)
{
	int	smallest;

	smallest = stack->head->elem;
	while (stack->node)
	{
		if (smallest > stack->node->elem)
			smallest = stack->node->elem;
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (smallest);
}

int	scnd_biggest_elem(t_stack *stack)
{
	int	scnd_biggest;
	int	biggest;

	biggest = biggest_elem_stack(stack);
	scnd_biggest = stack->head->elem;
	while (stack->node)
	{
		if (scnd_biggest < stack->node->elem && stack->node->elem != biggest)
			scnd_biggest = stack->node->elem;
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (scnd_biggest);
}

int	scnd_smallest_elem(t_stack *stack)
{
	int	smallest;
	int	scnd_smallest;

	smallest = smallest_elem_stack(stack);
	scnd_smallest = stack->node->elem;
	while (stack->node)
	{
		if (scnd_smallest > stack->node->elem && stack->node->elem != smallest)
			scnd_smallest = stack->node->elem;
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (scnd_smallest);
}

void	sort_aux_init(t_sort *sort_aux)
{
	sort_aux->elem = 0;
	sort_aux->idx = 0;
	sort_aux->mv = NULL;
	sort_aux->mv_qtd = INT_MAX / 2;
}
