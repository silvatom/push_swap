/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:48:38 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 17:42:11 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrx(t_stack *stack)
{
	t_node		*tail;

	if (stack && ft_dlstsize(stack->head) > 1)
	{
		tail = ft_dlstlast(stack->head);
		tail->prev->next = NULL;
		tail->next = stack->head;
		stack->head->prev = tail;
		stack->node = tail;
		stack->head = stack->node;
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rrx(stack_a);
	rrx(stack_b);
}
