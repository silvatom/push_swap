/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:36:49 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/26 20:31:13 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best_mv(t_stack *stack, t_aux *args_aux, t_sort *sort_aux, char c);

void	best_mv(t_stack *a, t_stack *b, t_aux *arg_aux, t_sort_aux *sort_aux);
/* FUNCTION to find the spot (or element) the B element needs to have on top of stack A */
int		find_elem(t_stack *stack, t_aux *args_aux, int b_elem, int side);

void	best_mv(t_stack *a, t_stack *b, t_aux *arg_aux, t_sort_aux *sort_aux)
{
	t_sort	elem_a_aux;
	t_sort	elem_b_aux;
	t_sort	temp_a;
	t_sort	temp_b;
	int		idx_elem_b;
	int		idx_elem_a;
	int		b_elem;
	int		a_elem;

	int		i;
	int		scnd_biggest_from_a;
	int		b_stack_size;

	temp_a.mv = NULL;
	temp_b.mv = NULL;
	elem_a_aux.mv = NULL;
	elem_b_aux.mv = NULL;
	temp_a.elem = 0;
	temp_b.elem = 0;
	elem_a_aux.mv_qtd = 0;
	elem_b_aux.mv_qtd = 0;
	sort_aux->elem2mv = 0;
	sort_aux->mv_qtd = 0;
	sort_aux->has_elem = FALSE;
	b_stack_size = ft_dlstsize(b->head);
	i = 0;
	/* Encontrar o melhor elemento para movimentar */
	while (i < b_stack_size)
	{
		/* PEGAR PROXIMO ELEMENTO DE B E PEGAR OS DETALHES PARA VER SE VER SE É BOM MOVMTO */
		b_elem = b->node->elem; //sort_aux->elem2mv = b->head->elem;
		idx_elem_b = find_pos_elem(b, b_elem);
		a_elem = 0; // A element required to be on top to pass B element above;
		scnd_biggest_from_a = scnd_biggest_elem(a);
		if (b_elem > scnd_biggest_from_a)
		{
			a_elem = biggest_elem_stack(a);
			idx_elem_a = find_pos_elem(a, a_elem);
		}
		else if (b_elem < scnd_biggest_from_a)
		{
			a_elem = find_elem(a, arg_aux, b_elem, UP);
			idx_elem_a = find_pos_elem(a, a_elem);
		}
		else
		{
			a_elem = find_elem(a, arg_aux, b_elem, UP);
			idx_elem_a = find_pos_elem(a, a_elem);
		}
		temp_a.elem = a_elem;
		temp_a.idx = idx_elem_a;
		temp_b.elem = b_elem;
		temp_b.idx = idx_elem_b;
		find_best_mv(a, arg_aux, &temp_a, 'a');
		find_best_mv(b, arg_aux, &temp_b, 'b');
		
		/* COMPARAR COM O ÚLTIMO ELEMENTO ENCONTRADO */
		if (sort_aux->has_elem == FALSE
			|| sort_aux->mv_qtd > (temp_a.mv_qtd + temp_b.mv_qtd))
		{
			sort_aux->elem2mv = b_elem;
			sort_aux->mv_qtd = temp_a.mv_qtd + temp_b.mv_qtd;
			elem_a_aux.elem = a_elem;
			elem_a_aux.idx = idx_elem_a;
			if (elem_a_aux.mv)
			{
				free(elem_a_aux.mv);
				elem_a_aux.mv = NULL;
			}
			elem_a_aux.mv = ft_strdup(temp_a.mv);
			elem_a_aux.mv_qtd = temp_a.mv_qtd;
			free(temp_a.mv);
			temp_a.mv = NULL;
			elem_b_aux.elem = b_elem;
			elem_b_aux.idx = idx_elem_b;
			if (elem_b_aux.mv)
			{
				free(elem_b_aux.mv);
				elem_b_aux.mv = NULL;
			}
			elem_b_aux.mv = ft_strdup(temp_b.mv);
			elem_b_aux.mv_qtd = temp_b.mv_qtd;
			free(temp_b.mv);
			temp_b.mv = NULL;
			sort_aux->has_elem = TRUE;
		}	
		if (temp_a.mv)
		{
			free(temp_a.mv);
			temp_a.mv = NULL;
		}
		if (temp_b.mv)
		{
			free(temp_b.mv);
			temp_b.mv = NULL;
		}	
		i++;
		b->node = b->node->next;
	}
	b->node = b->head;
	//movimentação
	if ((ft_strlen(elem_a_aux.mv) == 3
			&& ft_strncmp(elem_a_aux.mv, elem_b_aux.mv, 1) == 0)
		|| (ft_strlen(elem_a_aux.mv) == 4
			&& ft_strncmp(elem_a_aux.mv, elem_b_aux.mv, 2) == 0))
	{
		if (ft_strncmp(elem_a_aux.mv, "ra", ft_strlen("ra")) == 0)
		{
			// subtrair movimentos
			while (elem_a_aux.mv_qtd > 0 && elem_b_aux.mv_qtd > 0)
			{
				rr(a, b, &arg_aux->ops);
				elem_a_aux.mv_qtd--;
				elem_b_aux.mv_qtd--;
			}
			// ver se ainda tem mv pra fazer
			bring_elem2top(a, arg_aux, elem_a_aux.elem, "ra\n");
			bring_elem2top(b, arg_aux, elem_b_aux.elem, "rb\n");
		}
		else
		{
			// subtrair movimentos
			while (elem_a_aux.mv_qtd > 0 && elem_b_aux.mv_qtd > 0)
			{
				rrr(a, b, &arg_aux->ops);
				elem_a_aux.mv_qtd--;
				elem_b_aux.mv_qtd--;
			}
			// ver se ainda tem mv pra fazer
			bring_elem2top(a, arg_aux, elem_a_aux.elem, "rra\n");
			bring_elem2top(b, arg_aux, elem_b_aux.elem, "rrb\n");
		}
	}
	else
	{
		if (ft_strncmp(elem_a_aux.mv, "ra", ft_strlen("ra")) == 0)
		{
			// subtrair movimentos
			// ver se ainda tem mv pra fazer
			bring_elem2top(a, arg_aux, elem_a_aux.elem, "ra\n");
		}
		if (ft_strncmp(elem_b_aux.mv, "rb", ft_strlen("rb")) == 0)
			bring_elem2top(b, arg_aux, elem_b_aux.elem, "rb\n");
		if (ft_strncmp(elem_a_aux.mv, "rra", ft_strlen("rra")) == 0)
			bring_elem2top(a, arg_aux, elem_a_aux.elem, "rra\n");
		if (ft_strncmp(elem_b_aux.mv, "rrb", ft_strlen("rrb")) == 0)
			bring_elem2top(b, arg_aux, elem_b_aux.elem, "rrb\n");
	}
	px(a, b, &arg_aux->ops, "pa\n");
	if (elem_a_aux.mv)
		free(elem_a_aux.mv);
	if (elem_b_aux.mv)
		free(elem_b_aux.mv);
	elem_a_aux.mv = NULL;
	elem_b_aux.mv = NULL;
}

int	find_elem(t_stack *stack, t_aux *args_aux, int elem, int side)
{
	int	i;

	i = 0;
	while (args_aux->args_sorted[i] != elem)
		i++;
	if (side > 0 || ft_dlstsize(stack->head) == 2)
	{
		while (!has_element(stack, args_aux->args_sorted[i]) && i < args_aux->argc)
			i++;
	}
	else
	{
		while (!has_element(stack, args_aux->args_sorted[i]) && i < args_aux->argc)
			i--;
	}
	return (args_aux->args_sorted[i]);
}

