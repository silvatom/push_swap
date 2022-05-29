/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:48:41 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 17:59:25 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rx(t_stack *stack)
{
	t_node	*tail;

	if (stack && ft_dlstsize(stack->head) > 1)
	{
		tail = ft_dlstlast(stack->head);
		stack->node->prev = tail;
		tail->next = stack->node;
		stack->node->next->prev = NULL;
		stack->node = stack->node->next;
		stack->head->next = NULL;
		stack->head = stack->node;
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rx(stack_a);
	rx(stack_b);
}
