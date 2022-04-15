/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:42:33 by anjose-d          #+#    #+#             */
/*   Updated: 2022/04/15 19:04:51 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	**args;
	int		i;
	
	arg_check(argc, argv, &args);
	i = 0;
	while (args[i])
	{
		ft_printf("%d: %s\n", i, args[i]);
		i++;
	}
	destroy_matrix(args);
	return (0);
}
