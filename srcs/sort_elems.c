/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_elems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:25:44 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/13 01:33:09 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_aux *arg_aux);

void	sort_elems(t_stack *stack, t_aux *arg_aux)
{
	int	i;

	i = 0;
	arg_aux->args_sorted = malloc(ft_dlstsize(stack->head) * (sizeof(int) + 1));
	while (stack->node)
	{
		arg_aux->args_sorted[i] = stack->node->elem;
		stack->node = stack->node->next;
		i++;
	}
	// arg_aux->args_raw[i] = 0;
	// arg_aux->args_sorted[i] = 0;
	arg_aux->argc = i;
	stack->node = stack->head;
	bubble_sort(arg_aux);
}

void	bubble_sort(t_aux *arg_aux)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < arg_aux->argc - 1)
	{
		j = 0;
		while (j < arg_aux->argc - i - 1)
		{
			if (arg_aux->args_sorted[j] > arg_aux->args_sorted[j + 1])
			{
				tmp = arg_aux->args_sorted[j];
				arg_aux->args_sorted[j] = arg_aux->args_sorted[j + 1];
				arg_aux->args_sorted[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
