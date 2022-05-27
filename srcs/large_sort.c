/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:29:35 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/26 21:23:13 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Send the lesser half of A to B */
void	send_half(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux);

void	large_sort(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux)
{
	while (ft_dlstsize(stack_a->head) > 2)
	{
		if (ft_dlstsize(stack_a->head) > args_aux->argc / CHUNKS)
			send_half(stack_a, stack_b, args_aux);
		if ((stack_a->head->elem == args_aux->args_sorted[args_aux->argc - 1]
				|| stack_a->head->elem == args_aux->args_sorted[0]))
			rx(stack_a, &args_aux->ops, "ra\n");
		else if (ft_dlstsize(stack_a->head) > 2)
			px(stack_a, stack_b, &args_aux->ops, "pb\n");
	}
	biggest2top(stack_a, args_aux, NULL);
	while (ft_dlstsize(stack_b->head) != 0)
		send_back(stack_a, stack_b, args_aux);
	bring_elem2top(stack_a, args_aux, args_aux->args_sorted[0], "ra\n");
}

void	send_half(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux)
{
	int	i;
	int	idx_elem;

	i = 0;
	while (i < args_aux->argc / CHUNKS)
	{
		idx_elem = 0;
		while (args_aux->args_sorted[idx_elem] != stack_a->head->elem)
			idx_elem++;
		if (idx_elem <= args_aux->argc / 2 && idx_elem != 0
			&& idx_elem != args_aux->argc - 1)
		{
			px(stack_a, stack_b, &args_aux->ops, "pb\n");
			i++;
		}
		else
			rx(stack_a, &args_aux->ops, "ra\n");
	}
}
