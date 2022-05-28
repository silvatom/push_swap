/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 00:43:08 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/28 01:54:33 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	// // do the operations
	// // see if the operations did the job (check_desc_ordered and stack_b is empty)
	// ops = ops_str(&arg_aux);
	// ft_putstr_fd(ops, fd);
	
	// free(ops);
	ft_dlstclear(&stack_a.head, &free);
	// ft_lstclear(&arg_aux.ops, &free);
	// free(arg_aux.args_sorted);
	ft_destroy_matrix(arg_aux.args_raw);
	return (0);
}