/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:46:42 by anjose-d          #+#    #+#             */
/*   Updated: 2022/04/15 19:02:23 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_check(int argc, char *argv[], char ***splitted_args)
{
	int		i;
	char	*arg;
	char	*all_args;
	char	*temp;
	char	**check_args;

	if (argc < 2)
		return (-1);
	i = 1;
	all_args = ft_strdup("");
	while (i < argc)
	{
		if (str_spaced(argv[i]))
		{
			check_args = ft_split(argv[i], ' ');
			int	x = 0;
			while (check_args[x])
			{
				if (!valid_number(check_args[x]))
				{
					destroy_matrix(check_args);
					return (-1);
				}
				x++;
			} 
			arg = ft_strdup(argv[i]);
		}
		else
		{
			if (ft_strlen(argv[i]) == 1)
			{
				if (!ft_isdigit(argv[i][0]))
					return (-1);
				arg = ft_strdup(argv[i]);
			}
			else
			{
				if (!valid_number(argv[i]))
					return (-1);
				arg = ft_strdup(argv[i]);
			}
		}
		// colocar 'arg' in 'all_args'
		if (i != 1)
		{
			temp = all_args;
			all_args = ft_strjoin(temp, " ");
			free(temp);
		}
		temp = all_args;
		all_args = ft_strjoin(all_args, arg);
		free(arg);
		free(temp);
		i++;
	}
	ft_printf("%s!\n", all_args);
	*splitted_args = ft_split(all_args, ' ');
	free(all_args);
	return (0);
}
