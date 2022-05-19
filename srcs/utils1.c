/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:56:21 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/18 21:07:17 by anjose-d         ###   ########.fr       */
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

void	stack_init(t_stack *stack)
{
	stack->head = NULL;
	stack->node = NULL;
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
