/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ops_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:24:06 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 18:00:38 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/* Get input from STDIN until '\n'. Returns NULL with an EOF */
char	*get_input(void);
/* Returns 1 if the operation is invalid and 0 if everything went ok */
void	get_op(t_list **ops_lst, char *op);
/* Check if the input corresponds to a valid operation. Returns -1 if not. */
int		check_valid_op(char *input);

int	get_ops(t_list **ops_lst)
{
	char	*op;

	while (1)
	{
		op = get_input();
		if (op == NULL)
			return (0);
		if (check_valid_op(op))
		{
			free(op);
			close(STDIN_FILENO);
			return (1);
		}
		get_op(ops_lst, op);
		free(op);
	}
	return (1);
}

char	*get_input(void)
{
	char	*input;

	input = get_next_line(STDIN_FILENO);
	if (input == NULL)
	{
		free(input);
		return (NULL);
	}
	return (input);
}

void	get_op(t_list **ops_lst, char *op)
{
	t_list	*new_node;

	new_node = ft_lstnew((void *)ft_strdup(op));
	ft_lstadd_back(ops_lst, new_node);
}
