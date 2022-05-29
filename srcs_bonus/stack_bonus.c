/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:30:26 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 19:07:06 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

	if (is_empty(stack->node))
		return (INT_MIN);
	popped = stack->head->elem;
	ft_dlstrm_node(&stack->node, stack->head);
	stack->head = stack->node;
	return (popped);
}

int	is_empty(t_node *lst)
{
	return (!lst);
}

int	is_sorted_asc(t_stack *stack)
{
	t_node	*next;

	if (stack)
	{
		if (stack->node == NULL)
			return (FALSE);
		while (stack->node->next != NULL)
		{
			next = stack->node->next;
			if (next->elem <= stack->node->elem)
			{
				stack->node = stack->head;
				return (FALSE);
			}
			stack->node = stack->node->next;
		}
	}
	stack->node = stack->head;
	return (TRUE);
}

int	has_element(t_stack *stack, int elem)
{
	while (stack->node)
	{
		if (stack->node->elem == elem)
		{
			stack->node = stack->head;
			return (1);
		}
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (0);
}
