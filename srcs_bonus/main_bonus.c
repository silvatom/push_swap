/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 00:43:08 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 19:32:51 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	free_vars(t_stack *stack_a, t_aux *arg_aux);

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_aux	arg_aux;

	arg_aux.ops = NULL;
	if (argc < 2 || arg_check(argc, argv, &arg_aux))
	{
		if (argc == 1)
			return (0);
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (-1);
	}
	feed_stack(&stack_a, &arg_aux);
	if (get_ops(&arg_aux.ops))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		free_vars(&stack_a, &arg_aux);
		return (-1);
	}
	checker(&stack_a, &arg_aux);
	free_vars(&stack_a, &arg_aux);
	return (0);
}

static void	free_vars(t_stack *stack_a, t_aux *arg_aux)
{
	t_list	*head;

	ft_dlstclear(&stack_a->head, &free);
	head = arg_aux->ops;
	while (arg_aux->ops)
	{
		free(arg_aux->ops->content);
		arg_aux->ops = arg_aux->ops->next;
	}
	arg_aux->ops = head;
	ft_lstclear(&arg_aux->ops, &free);
	ft_destroy_matrix(arg_aux->args_raw);
}
