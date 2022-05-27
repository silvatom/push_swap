/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:55:19 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/27 00:03:19 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_spot(t_stack *stack, t_aux *args_aux, int a_elem, int side)
{
	int	i;

	i = 0;
	while (args_aux->args_sorted[i] != a_elem)
		i++;
	if (side > 0)
	{
		while (!has_element(stack, args_aux->args_sorted[i])
			&& i < args_aux->argc)
			i += side;
	}
	bring_elem2top(stack, args_aux, args_aux->args_sorted[i], "ra\n");
}

void	find_mv(t_stack *stack, t_aux *args_aux, t_sort *sort_aux, char c)
{
	int		mvs;
	int		stack_size;
	char	*mv;

	mvs = 0;
	sort_aux->idx = find_pos_elem(stack, sort_aux->elem);
	stack_size = ft_dlstsize(stack->head);
	if (sort_aux->idx <= (stack_size / 2))
	{
		sort_aux->mv_qtd = sort_aux->idx;
		if (c == 'a')
			sort_aux->mv = ft_strdup("ra\n");
		else
			sort_aux->mv = ft_strdup("rb\n");
	}
	else
	{
		sort_aux->mv_qtd = stack_size - sort_aux->idx;
		if (c == 'a')
			sort_aux->mv = ft_strdup("rra\n");
		else
			sort_aux->mv = ft_strdup("rrb\n");
	}
}

void	biggest2top(t_stack *stack, t_aux *args_aux, char *op)
{
	int	biggest;

	if (ft_dlstsize(stack->head) < 2)
		return ;
	biggest = biggest_elem_stack(stack);
	bring_elem2top(stack, args_aux, biggest, op);
}

int	find_pos_elem(t_stack *stack, int elem)
{
	int		index;
	t_node	*tmp;

	index = 0;
	tmp = stack->head;
	while (tmp)
	{
		if (tmp->elem == elem)
			break ;
		index++;
		tmp = tmp->next;
	}
	tmp = NULL;
	return (index);
}

void	bring_elem2top(t_stack *stack, t_aux *args_aux, int elem, char *op)
{
	t_sort	sort_aux;

	if (ft_dlstsize(stack->head) < 2)
		return ;
	sort_aux.idx = find_pos_elem(stack, elem);
	sort_aux.elem = elem;
	find_mv(stack, args_aux, &sort_aux, stack->flag);
	while (stack->head->elem != elem)
	{
		if (stack->flag == 'a')
		{
			if (ft_strncmp(sort_aux.mv, "ra", ft_strlen("ra")) == 0)
				rx(stack, &args_aux->ops, "ra\n");
			else
				rrx(stack, &args_aux->ops, "rra\n");
		}
		else
		{
			if (ft_strncmp(sort_aux.mv, "rb", ft_strlen("rb")) == 0)
				rx(stack, &args_aux->ops, "rb\n");
			else
				rrx(stack, &args_aux->ops, "rrb\n");
		}
	}
	free(sort_aux.mv);
}
