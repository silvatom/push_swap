/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:29:35 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/18 21:32:13 by anjose-d         ###   ########.fr       */
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
			printf("pushed: %d\n", stack_a->head->elem);
			px(stack_a, stack_b, &args_aux->ops, "pb\n");
				// antes de passar para b, verificar se o número a ser passado é
				// o maior ou menor de todos, para saber o lugar correto de colocar o número
			i++;
		}
		ft_printf("| ");
		chunk_nbr++;
	}
	while (ft_dlstsize(stack_b->node) > 0)
	{
		px(stack_a, stack_b, &args_aux->ops, "pa\n");
	}





	
	// int	i;
	// int	mv_count;
	// int	chunk_nbr;
	// t_sort_aux sort_aux;

	// i = 0; 
	// chunk_nbr = 0;
	// while (ft_dlstsize(stack_a->node) > 0 && i < args_aux->argc)
	// {
	// 	i = (args_aux->argc / CHUNKS) * chunk_nbr; // top chunk;
	// 	while (i < (args_aux->argc / CHUNKS) * (chunk_nbr + 1) && i < args_aux->argc) // iterando dentro do chunk
	// 	{
	// 		sort_aux.ck_end1 = i;
	// 		sort_aux.ck_end2 = (args_aux->argc / CHUNKS) * (chunk_nbr + 1);
			
			




			
	// 		// antes de passar para b, verificar se o número a ser passado é
	// 		// o maior ou menor de todos, para saber o lugar correto de colocar o número
	// 		ft_printf("%d ", args_aux->args_sorted[i]);
	// 		i++;
	// 	}
	// 	ft_printf("| ");
	// 	chunk_nbr++;
	// }
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
	while (!has_element(stack, args_aux->args_sorted[i]) /*não estiver presente na stack_a*/)
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
			sort_aux->mv = ft_strdup(temp.mv);
			free(temp.mv);
			temp.mv = NULL;
			sort_aux->mv_qtd = temp.mv_qtd;
			sort_aux->has_elem = TRUE;
		}
		ft_printf("%d ", args_aux->args_sorted[i]);
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
	if (sort_aux->idx <= (args_aux->argc / 2)) // ra;
	{
		sort_aux->mv_qtd = sort_aux->idx;
		sort_aux->mv = ft_strdup("ra");
	}
	else									// rra;
	{
		sort_aux->mv_qtd = args_aux->argc - sort_aux->idx;
		sort_aux->mv = ft_strdup("rra");
	}
}

	// while (i < args_aux->argc)
	// {
	// 	while (stack_a->node->elem != args_aux->args_sorted[i])
	// 		rx(stack_a, &args_aux->ops, "ra\n");
	// 	px(stack_a, stack_b, &args_aux->ops, "pb\n");
	// 	i++;
	// }
	// while (ft_dlstsize(stack_b->head) > 0)
	// {
	// 	px(stack_a, stack_b, &args_aux->ops, "pa\n");
	// }