/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:48:41 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/12 20:17:48 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rx(t_stack *stack, t_list **ops, const char *op)
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
	if (op != NULL)
		ft_lstadd_back(ops, ft_lstnew((void *)op));
}

void	rr(t_stack *stack_a, t_stack *stack_b, t_list **ops)
{
	rx(stack_a, ops, NULL);
	rx(stack_b, ops, NULL);
	ft_lstadd_back(ops, ft_lstnew("rr\n"));
}
