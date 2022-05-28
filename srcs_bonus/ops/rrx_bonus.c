/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:48:38 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/28 01:39:44 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrx(t_stack *stack, t_list **ops, const char *op)
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
	if (op != NULL)
		ft_lstadd_back(ops, ft_lstnew((void *)op));
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_list **ops)
{
	rrx(stack_a, ops, NULL);
	rrx(stack_b, ops, NULL);
	ft_lstadd_back(ops, ft_lstnew("rrr\n"));
}
