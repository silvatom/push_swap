/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:48:38 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/06 01:57:57 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_stack *stack)
{
	t_node	*tail;

	if (stack && ft_dlstsize(stack->head) > 1)
	{
		tail = ft_dlstlast(stack->head);
		tail->next = stack->head;
		stack->head->prev = tail;
		tail->prev->next = NULL;
		stack->node = tail;
		stack->head = stack->node;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrx(stack_a);
	rrx(stack_b);
}
