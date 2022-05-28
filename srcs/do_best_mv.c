/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_mv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 01:11:29 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/28 00:58:45 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* function to check if both stacks share the same moviment */
static int	check_same_mv(t_aux *arg_aux);
/* function to move both stacks at the same time (syncronized) */
static void	sync_mv(t_stack *a, t_stack *b, t_aux *arg_aux);
/* function to move stacks one at a time */
static void	async_mv(t_stack *a, t_stack *b, t_aux *arg_aux);

/* do the changes found by find_best_mv */
void	do_best_mv(t_stack *a, t_stack *b, t_aux *arg_aux)
{
	if (check_same_mv(arg_aux))
		sync_mv(a, b, arg_aux);
	else
		async_mv(a, b, arg_aux);
	px(a, b, &arg_aux->ops, "pa\n");
	if (arg_aux->a_aux->mv)
		free(arg_aux->a_aux->mv);
	if (arg_aux->b_aux->mv)
		free(arg_aux->b_aux->mv);
}

static int	check_same_mv(t_aux *arg_aux)
{
	if ((ft_strlen(arg_aux->a_aux->mv) == 3
			&& ft_strncmp(arg_aux->a_aux->mv, arg_aux->b_aux->mv, 1) == 0)
		|| (ft_strlen(arg_aux->a_aux->mv) == 4
			&& ft_strncmp(arg_aux->a_aux->mv, arg_aux->b_aux->mv, 2) == 0))
	{
		return (1);
	}
	return (0);
}

static void	sync_mv(t_stack *a, t_stack *b, t_aux *arg_aux)
{
	if (ft_strncmp(arg_aux->a_aux->mv, "ra", ft_strlen("ra")) == 0)
	{
		while (arg_aux->a_aux->mv_qtd > 0 && arg_aux->b_aux->mv_qtd > 0)
		{
			rr(a, b, &arg_aux->ops);
			arg_aux->a_aux->mv_qtd--;
			arg_aux->b_aux->mv_qtd--;
		}
		bring_elem2top(a, arg_aux, arg_aux->a_aux->elem);
		bring_elem2top(b, arg_aux, arg_aux->b_aux->elem);
	}
	else
	{
		while (arg_aux->a_aux->mv_qtd > 0 && arg_aux->b_aux->mv_qtd > 0)
		{
			rrr(a, b, &arg_aux->ops);
			arg_aux->a_aux->mv_qtd--;
			arg_aux->b_aux->mv_qtd--;
		}
		bring_elem2top(a, arg_aux, arg_aux->a_aux->elem);
		bring_elem2top(b, arg_aux, arg_aux->b_aux->elem);
	}
}

static void	async_mv(t_stack *a, t_stack *b, t_aux *arg_aux)
{
	if (ft_strncmp(arg_aux->a_aux->mv, "ra", ft_strlen("ra")) == 0)
		bring_elem2top(a, arg_aux, arg_aux->a_aux->elem);
	if (ft_strncmp(arg_aux->b_aux->mv, "rb", ft_strlen("rb")) == 0)
		bring_elem2top(b, arg_aux, arg_aux->b_aux->elem);
	if (ft_strncmp(arg_aux->a_aux->mv, "rra", ft_strlen("rra")) == 0)
		bring_elem2top(a, arg_aux, arg_aux->a_aux->elem);
	if (ft_strncmp(arg_aux->b_aux->mv, "rrb", ft_strlen("rrb")) == 0)
		bring_elem2top(b, arg_aux, arg_aux->b_aux->elem);
}
