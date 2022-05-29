/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:14:56 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 19:04:04 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	do_operations(t_stack *a, t_aux *arg_aux);
static void	which_operation(t_stack *a, t_stack *b, char *op);
static int	check_right_size(t_stack *a, t_aux *arg_aux);
static int	check_invalid_order(t_stack *a, t_aux *arg_aux);

void	checker(t_stack *a, t_aux *arg_aux)
{
	do_operations(a, arg_aux);
	if (check_invalid_order(a, arg_aux))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

static void	do_operations(t_stack *a, t_aux *arg_aux)
{
	t_stack	b;
	t_list	*head;

	stack_init(&b, 'b');
	head = arg_aux->ops;
	while (arg_aux->ops)
	{
		which_operation(a, &b, (char *)arg_aux->ops->content);
		arg_aux->ops = arg_aux->ops->next;
	}
	arg_aux->ops = head;
	ft_dlstclear(&b.head, &free);
}

static void	which_operation(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "sa\n", ft_strlen("sa\n")) == 0)
		sx(a);
	else if (ft_strncmp(op, "sb\n", ft_strlen("sb\n")) == 0)
		sx(b);
	else if (ft_strncmp(op, "ss\n", ft_strlen("ss\n")) == 0)
		ss(a, b);
	else if (ft_strncmp(op, "pa\n", ft_strlen("pa\n")) == 0)
		px(a, b, op);
	else if (ft_strncmp(op, "pb\n", ft_strlen("pb\n")) == 0)
		px(a, b, op);
	else if (ft_strncmp(op, "ra\n", ft_strlen("ra\n")) == 0)
		rx(a);
	else if (ft_strncmp(op, "rb\n", ft_strlen("rb\n")) == 0)
		rx(b);
	else if (ft_strncmp(op, "rr\n", ft_strlen("rr\n")) == 0)
		rr(a, b);
	else if (ft_strncmp(op, "rra\n", ft_strlen("rra\n")) == 0)
		rrx(a);
	else if (ft_strncmp(op, "rrb\n", ft_strlen("rrb\n")) == 0)
		rrx(b);
	else if (ft_strncmp(op, "rrr\n", ft_strlen("rrr\n")) == 0)
		rrr(a, b);
}

static int	check_invalid_order(t_stack *a, t_aux *arg_aux)
{
	if (check_right_size(a, arg_aux))
		return (-1);
	if (!is_sorted_asc(a))
		return (-1);
	return (0);
}

static int	check_right_size(t_stack *a, t_aux *arg_aux)
{
	int	a_size;

	a_size = ft_dlstsize(a->head);
	if (a_size != arg_aux->argc)
		return (-1);
	return (0);
}
