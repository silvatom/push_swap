/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:42:33 by anjose-d          #+#    #+#             */
/*   Updated: 2022/04/19 23:47:54 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**args_str;
	int		i;
	
	if (argc < 2 || arg_check(argc, argv, &args_str))
	{
		ft_printf("Error\n");
		destroy_matrix(args_str);
		return (-1);
	}
	i = 0;
	if (args_str)
	{
		while (args_str[i])
		{
			ft_printf("%d: %s\n", i, args_str[i]);
			i++;
		}
		destroy_matrix(args_str);
	}
	
	return (0);
}
