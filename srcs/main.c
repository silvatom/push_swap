/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:42:33 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/22 12:40:09 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops(char *ops);

int		main(int argc, char *argv[])
{
	char	*ops;
	t_stack	stack_a;
	t_aux	arg_aux;
	int		fd = 1;

	if (argc < 2 || arg_check(argc, argv, &arg_aux))
	{
		ft_putstr_fd("Error\n", fd);
		return (-1);
	}
	feed_stack(&stack_a, &arg_aux);
	sort_elems(&stack_a, &arg_aux);
	sort_stack(&stack_a, &arg_aux);
	ops = ops_str(&arg_aux);
	ft_putstr_fd(ops, fd);
	free(ops);
	ft_dlstclear(&stack_a.head, &free);
	ft_lstclear(&arg_aux.ops, &free);
	free(arg_aux.args_sorted);
	ft_destroy_matrix(arg_aux.args_raw);
	return (0);
}

char	*optimize(t_aux *args_aux)
{
	t_list	*head;

	head = args_aux->ops;
	while (args_aux->ops->next)
	{
		if ((ft_strncmp(args_aux->ops->content, "ra", 2) == 0 && ft_strncmp(args_aux->ops->next->content, "rb", 2) == 0) ||
			(ft_strncmp(args_aux->ops->content, "rb", 2) == 0 && ft_strncmp(args_aux->ops->next->content, "ra", 2) == 0))
			{
				
			}
	}
	args_aux->ops = head;
	return (char *)args_aux->ops;
}
