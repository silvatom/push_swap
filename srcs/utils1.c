/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:56:21 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/25 10:53:59 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_spaced(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	stack_init(t_stack *stack, char flag)
{
	stack->head = NULL;
	stack->node = NULL;
	stack->flag = flag;
}

char	*ops_str(t_aux *args_aux)
{
	char	*ret;
	char	*tmp;
	t_list	*head;

	ret = ft_strdup("");
	head = args_aux->ops;
	while (args_aux->ops)
	{
		tmp = ret;
		ret = ft_strjoin(ret, args_aux->ops->content);
		free(tmp);
		args_aux->ops = args_aux->ops->next;
	}
	args_aux->ops = head;
	return (ret);
}

int	biggest_elem_stack(t_stack *stack)
{
	int	biggest;

	biggest = stack->head->elem;
	while (stack->node)
	{
		if (biggest < stack->node->elem)
			biggest = stack->node->elem;
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (biggest);
}

int	smallest_elem_stack(t_stack *stack)
{
	int	smallest;

	smallest = stack->head->elem;
	while (stack->node)
	{
		if (smallest > stack->node->elem)
			smallest = stack->node->elem;
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (smallest);
}

void	biggest2top(t_stack *stack, t_aux *args_aux, char *op)
{
	int	biggest;
	
	if (ft_dlstsize(stack->head) < 2)
		return ;
	biggest = biggest_elem_stack(stack);
	bring_elem2top(stack, args_aux, biggest, op);
	// while (stack->head->elem != biggest)
	// {
	// 	// find best movement
	// 	rx(stack, &args_aux->ops, "rb\n");
	// }
}

void	smallest2top(t_stack *stack, t_aux *args_aux)
{
	int	smallest;
	
	if (ft_dlstsize(stack->head) < 2)
		return ;
	smallest = smallest_elem_stack(stack);
	while (stack->head->elem != smallest)
	{
		// find best movement
		rx(stack, &args_aux->ops, "rb\n");
	}
}

int	scnd_biggest_elem(t_stack *stack)
{
	int	scnd_biggest;
	int	biggest;

	biggest = biggest_elem_stack(stack);
	scnd_biggest = stack->head->elem;
	while (stack->node)
	{
		if (scnd_biggest < stack->node->elem && stack->node->elem != biggest)
			scnd_biggest = stack->node->elem;
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (scnd_biggest);
}

int	scnd_smallest_elem(t_stack *stack)
{
	int	smallest;
	int	scnd_smallest;

	smallest = smallest_elem_stack(stack);
	scnd_smallest = stack->node->elem;
	while (stack->node)
	{
		if (scnd_smallest > stack->node->elem && stack->node->elem != smallest)
			scnd_smallest = stack->node->elem;
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (scnd_smallest);
}

void	bring_elem2top(t_stack *stack, t_aux *args_aux, int	elem, char *op)
{
	t_sort	sort_aux;
	
	if (ft_dlstsize(stack->head) < 2)
		return ;
	sort_aux.idx = find_pos_elem(stack, elem);
	sort_aux.elem = elem;
	find_best_mv1(stack, args_aux, &sort_aux, stack->flag);
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
		// 	sort_aux.mv_qtd--;
		// }
		// find best movement
		// rx(stack, &args_aux->ops, op);
	}
	free(sort_aux.mv);
}

void	bring_elem2tail(t_stack *stack, t_aux *args_aux, int elem)
{
	t_node	*tail;
	if (ft_dlstsize(stack->head) < 2)
		return ;
	tail = ft_dlstlast(stack->head);
	while (tail->elem != elem)
	{
		// find best movement
		rx(stack, &args_aux->ops, "rb\n");
		tail = ft_dlstlast(stack->head);
	}
	tail = NULL;
}

void	find_spot(t_stack *stack, t_aux *args_aux, int a_elem, int side)
{
	int	i;

	i = 0;
	while (args_aux->args_sorted[i] != a_elem)
		i++;
	if (side > 0)
	{
		while (!has_element(stack, args_aux->args_sorted[i]) && i < args_aux->argc)
			i += side;
	}
	// while (args_aux->args_sorted[i] != a_elem)
	// 	i++;
	// i--;
	// while (!has_element(stack, args_aux->args_sorted[i]) && i >= 0)
	// 	i--;
	bring_elem2top(stack, args_aux, args_aux->args_sorted[i], "ra\n");
}
