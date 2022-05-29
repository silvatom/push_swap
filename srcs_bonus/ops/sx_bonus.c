/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:48:44 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 18:00:01 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sx(t_stack *stack)
{
	t_node	*tmp;

	if (stack && ft_dlstsize(stack->head) > 1)
	{
		tmp = stack->node->next;
		stack->node->next = stack->node->next->next;
		stack->node->prev = tmp;
		stack->node = tmp;
		tmp->prev = NULL;
		tmp->next = stack->head;
		stack->head = stack->node;
		if (ft_dlstsize(stack->head) > 2)
			stack->head->next->next->prev = stack->node->next;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sx(stack_a);
	sx(stack_b);
}
