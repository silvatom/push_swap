/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:44:21 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/27 01:33:21 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	cmp_mv(t_sort *a_aux, t_sort *b_aux, t_sort *tmp_a, t_sort *tmp_b);

/* Find the best move combination and compare with the previously got */
void	best_mv(t_sort *a_aux, t_sort *b_aux, t_sort *temp_a, t_sort *temp_b)
{
	if (a_aux->mv_qtd + b_aux->mv_qtd
		> (temp_a->mv_qtd + temp_b->mv_qtd))
		cmp_mv(a_aux, b_aux, temp_a, temp_b);
	free(temp_a->mv);
	free(temp_b->mv);
}

static void	cmp_mv(t_sort *a_aux, t_sort *b_aux, t_sort *tmp_a, t_sort *tmp_b)
{
	a_aux->elem = tmp_a->elem;
	a_aux->idx = tmp_a->idx;
	if (a_aux->mv)
	{
		free(a_aux->mv);
		a_aux->mv = NULL;
	}
	a_aux->mv = ft_strdup(tmp_a->mv);
	a_aux->mv_qtd = tmp_a->mv_qtd;
	free(tmp_a->mv);
	tmp_a->mv = NULL;
	b_aux->elem = tmp_b->elem;
	b_aux->idx = tmp_b->idx;
	if (b_aux->mv)
	{
		free(b_aux->mv);
		b_aux->mv = NULL;
	}
	b_aux->mv = ft_strdup(tmp_b->mv);
	b_aux->mv_qtd = tmp_b->mv_qtd;
	free(tmp_b->mv);
	tmp_b->mv = NULL;
}
