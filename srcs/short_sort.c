/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:13:17 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/18 21:12:47 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_three(t_stack *stack_a, t_aux *args_aux);
void	until_a_3(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux);
void	bring_back_to_a(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux);

void	short_sort(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux)
{
		until_a_3(stack_a, stack_b, args_aux);
		short_three(stack_a, args_aux);
		bring_back_to_a(stack_a, stack_b, args_aux);
}

void	short_three(t_stack *stack_a, t_aux *args_aux)
{
	if (args_aux->argc == 2)
	{
		sx(stack_a, &args_aux->ops, "sa\n");
		return ;
	}
	if ((stack_a->head->elem == args_aux->args_sorted[0] &&
		stack_a->head->next->elem == args_aux->args_sorted[2] &&
		stack_a->head->next->next->elem == args_aux->args_sorted[1]) ||
		(stack_a->head->elem == args_aux->args_sorted[1] &&
		stack_a->head->next->elem == args_aux->args_sorted[0] &&
		stack_a->head->next->next->elem == args_aux->args_sorted[2]) ||
		(stack_a->head->elem == args_aux->args_sorted[2] &&
		stack_a->head->next->elem == args_aux->args_sorted[1] &&
		stack_a->head->next->next->elem == args_aux->args_sorted[0])
		)
			sx(stack_a, &args_aux->ops, "sa\n");
	if (stack_a->head->elem == args_aux->args_sorted[1] &&
		stack_a->head->next->elem == args_aux->args_sorted[2] &&
		stack_a->head->next->next->elem == args_aux->args_sorted[0])
			rrx(stack_a, &args_aux->ops, "rra\n");
	if (stack_a->head->elem == args_aux->args_sorted[2] &&
		stack_a->head->next->elem == args_aux->args_sorted[0] &&
		stack_a->head->next->next->elem == args_aux->args_sorted[1])
			rx(stack_a, &args_aux->ops, "ra\n");
}

void	until_a_3(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux)
{
	while (ft_dlstsize(stack_a->head) > 3)
	{
		if (stack_a->head->elem != args_aux->args_sorted[0] &&
		stack_a->head->elem != args_aux->args_sorted[1] &&
		stack_a->head->elem != args_aux->args_sorted[2])
		{
			px(stack_a, stack_b, &args_aux->ops, "pb\n");
		}
		else
			rx(stack_a, &args_aux->ops, "ra\n");
	}
}

void	bring_back_to_a(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux)
{
	int	next_idx;

	next_idx = 3;
	while (!is_empty(stack_b->node))
	{
		while (stack_b->head->elem != args_aux->args_sorted[next_idx])
			rx(stack_b, &args_aux->ops, "rb\n");
		px(stack_a, stack_b, &args_aux->ops, "pa\n");
		rx(stack_a, &args_aux->ops, "ra\n");
		next_idx++;
	}
}
