/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:08:47 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/18 21:12:39 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *stack_a, t_aux *args_aux)
{
	t_stack 	stack_b;

	args_aux->ops = NULL;
	stack_init(&stack_b);
	if (is_sorted_desc(stack_a))
		return ;
	if (args_aux->argc <= 5)
	 	short_sort(stack_a, &stack_b, args_aux);
	else
		large_sort(stack_a, &stack_b, args_aux);
}
