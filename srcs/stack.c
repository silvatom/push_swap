/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:30:26 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/05 17:41:56 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_push(t_stack *stack, int data)
{
	t_node	*new_node;

	new_node = ft_dlstnew(data);
	if (!new_node)
		return (-1);
	if (!stack->node)
		stack->node = new_node;
	else
		ft_dlstadd_front(&stack->node, new_node);
	stack->head = stack->node;	
	return (0);
}

int	stack_pop(t_stack *stack)
{
	int	popped;

	if (isEmpty(stack->node))
		return (INT_MIN);
	popped = stack->head->elem;
	ft_dlstrm_node(&stack->node, stack->head);
	stack->head = stack->node;
	return (popped);
}

int	isEmpty(t_node *lst)
{
	return !lst;
}