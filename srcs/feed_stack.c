/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   feed_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:26:17 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/25 10:45:01 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	feed_stack(t_stack *stack_a, t_aux *args_aux)
{
	int	argc;
	int	nbr;

	argc = args_aux->argc - 1;
	stack_init(stack_a, 'a');
	while (argc >= 0)
	{
		nbr = ft_atoi(args_aux->args_raw[argc]);
		stack_push(stack_a, nbr);
		argc--;
	}
}
