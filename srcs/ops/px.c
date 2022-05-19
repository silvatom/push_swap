/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:48:34 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/18 21:13:05 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack *stack_a, t_stack *stack_b, t_list **ops, char const *op)
{
	int		popped;

	if (ft_strncmp(op, "pa\n", ft_strlen(op)) == 0)
	{
		if (!is_empty(stack_b->node))
		{
			popped = stack_pop(stack_b);
			stack_push(stack_a, popped);
		}
	}
	else if (ft_strncmp(op, "pb\n", ft_strlen(op)) == 0)
	{
		if (!is_empty(stack_a->node))
		{
			popped = stack_pop(stack_a);
			stack_push(stack_b, popped);
		}
	}
	ft_lstadd_back(ops, ft_lstnew((void *)op));
}