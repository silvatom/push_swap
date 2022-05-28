/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:42:33 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/28 00:46:02 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	*ops;
	t_stack	stack_a;
	t_aux	arg_aux;

	if (argc < 2 || arg_check(argc, argv, &arg_aux))
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (-1);
	}
	feed_stack(&stack_a, &arg_aux);
	sort_elems(&stack_a, &arg_aux);
	sort_stack(&stack_a, &arg_aux);
	ops = ops_str(&arg_aux);
	ft_putstr_fd(ops, STDOUT_FILENO);
	free(ops);
	ft_dlstclear(&stack_a.head, &free);
	ft_lstclear(&arg_aux.ops, &free);
	free(arg_aux.args_sorted);
	ft_destroy_matrix(arg_aux.args_raw);
	return (0);
}
