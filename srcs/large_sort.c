/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:29:35 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/20 21:03:22 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closest_elem(t_stack *stack, t_aux *args_aux, t_sort_aux *sort_aux);
int	find_pos_elem(t_stack *stack, int elem);
void	find_best_mv(t_aux *args_aux, t_sort_aux *sort_aux);

void	large_sort(t_stack *stack_a, t_stack *stack_b, t_aux *args_aux)
{
	int	i;
	int	j;
	int	mv_count;
	int	chunk_nbr;
	t_sort_aux sort_aux;


	i = 0; 
	chunk_nbr = 0;
	sort_aux.mv = NULL;
	while (ft_dlstsize(stack_a->node) > 0 && i < args_aux->argc)
	{
		i = (args_aux->argc / CHUNKS) * chunk_nbr; // chunk's top;
		sort_aux.ck_end1 = i;
		sort_aux.ck_end2 = (args_aux->argc / CHUNKS) * (chunk_nbr + 1); // chunk's bottom
		while (i < (args_aux->argc / CHUNKS) * (chunk_nbr + 1) && i < args_aux->argc)
		{
			closest_elem(stack_a, args_aux, &sort_aux);
			while (sort_aux.mv_qtd > 0)
			{
				if (ft_strncmp(sort_aux.mv, "ra", ft_strlen("ra")) == 0)
					rx(stack_a, &args_aux->ops, "ra\n");
				else
					rrx(stack_a, &args_aux->ops, "rra\n");
				sort_aux.mv_qtd--;
			}
			// verificação antes de passar pra head_A para B
			if (ft_dlstsize(stack_b->head) > 0 && stack_a->head->elem > biggest_elem_stack(stack_b))
			{
				//smallest2top(stack_b, args_aux);
				biggest2top(stack_b, args_aux);
				// trazer maior elemento para o topo de B
			}
			else if (ft_dlstsize(stack_b->head) > 0 && stack_a->head->elem < smallest_elem_stack(stack_b))
			{
				biggest2top(stack_b, args_aux);
				// trazer o menor elemento para o topo de B?
			}
			else if (ft_dlstsize(stack_b->head) > 0)
			{
				find_middle_spot(stack_b, args_aux, stack_a->head->elem);
				//traz a posição -1 (sorted) pro topo de B
			}
			// antes de passar para b, verificar se o número a ser passado é
			// o maior ou menor de todos, para saber o lugar correto de colocar o número
			px(stack_a, stack_b, &args_aux->ops, "pb\n");
			free(sort_aux.mv);
			sort_aux.mv = NULL;

			i++;
		}
		chunk_nbr++;
	}
	biggest2top(stack_b, args_aux);
	while (ft_dlstsize(stack_b->node) > 0)
	// antes de começar, ver se A está ordenado e se B está ordenado ao contrário
		px(stack_a, stack_b, &args_aux->ops, "pa\n");
}



int	closest_elem(t_stack *stack, t_aux *args_aux, t_sort_aux *sort_aux)
{
	int	index;
	int	i;
	int	nbr;
	t_sort_aux temp;

	index = 0;
	i = sort_aux->ck_end1;
	sort_aux->has_elem = FALSE;	/* criar init para esta estrutura */
	sort_aux->mv_qtd = 0;
	while (i < args_aux->argc && !has_element(stack, args_aux->args_sorted[i]) /*não estiver presente na stack_a*/)
		i++;
	while (i < sort_aux->ck_end2 && i < args_aux->argc && has_element(stack, args_aux->args_sorted[i]))
	{
		// args_sorted está presente? se 
		temp.elem2mv = args_aux->args_sorted[i];
		temp.idx = find_pos_elem(stack, temp.elem2mv);
		find_best_mv(args_aux, &temp);
		if (sort_aux->has_elem == FALSE || temp.mv_qtd < sort_aux->mv_qtd)
		{
			sort_aux->elem2mv = temp.elem2mv;
			sort_aux->idx = temp.idx;
			if (sort_aux->mv)
			{
				free(sort_aux->mv);
				sort_aux->mv = NULL;
			}
			sort_aux->mv = ft_strdup(temp.mv);
			sort_aux->mv_qtd = temp.mv_qtd;
			sort_aux->has_elem = TRUE;
		}
		if (temp.mv)
			free(temp.mv);
		// ft_printf("%d ", args_aux->args_sorted[i]);
		i++;
	}
	return (index);
}

int	find_pos_elem(t_stack *stack, int elem)
{
	int	index;

	index = 0;
	while (stack->node)
	{
		if (stack->node->elem == elem)
			break ;
		index++;
		stack->node = stack->node->next;
	}
	stack->node = stack->head;
	return (index);
}

void	find_best_mv(t_aux *args_aux, t_sort_aux *sort_aux)
{
	int	mvs;

	mvs = 0;
	if (sort_aux->idx <= (args_aux->argc / 2))		// ra;
	{
		sort_aux->mv_qtd = sort_aux->idx;
		sort_aux->mv = ft_strdup("ra");
	}
	else											// rra;
	{
		sort_aux->mv_qtd = args_aux->argc - sort_aux->idx;
		sort_aux->mv = ft_strdup("rra");
	}
}
