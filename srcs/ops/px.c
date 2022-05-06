/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:48:34 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/06 01:39:34 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	px(t_stack *stack_a, t_stack *stack_b, char const *op)
{
	int	popped;

	if (ft_strncmp(op, "pa", ft_strlen(op)) == 0)
	{
		if (!isEmpty(stack_b->node))
		{
			popped = stack_pop(stack_b);
			stack_push(stack_a, popped);
		}
	}
	else if (ft_strncmp(op, "pb", ft_strlen(op)) == 0)
	{
		if (!isEmpty(stack_a->node))
		{
			popped = stack_pop(stack_a);
			stack_push(stack_b, popped);
		}
	}
}