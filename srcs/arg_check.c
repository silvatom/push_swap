/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:46:42 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/14 00:56:15 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* check equal results */
static int	nbr_validation(char **args);
/* do simple validations to the arguments given */
static int	check_invalid_arg(char *raw_arg, char **arg);
/* append 'arg' into 'all_args' */
static void	join_args(char **actual_args, char *new_arg, int index);
/* little abstraction to follow the norm */
static int	nbr_checking(char **splitted_args);

int	arg_check(int argc, char *argv[], t_aux *args_aux)
{
	int		i;
	char	*arg;
	char	*all_args;

	args_aux->args_raw = NULL;
	i = 0;
	all_args = ft_strdup("");
	while (++i < argc)
	{
		if (check_invalid_arg(argv[i], &arg))
		{
			free(all_args);
			return (-1);
		}
		join_args(&all_args, arg, i);
		free(arg);
	}
	args_aux->args_raw = ft_split(all_args, ' ');
	free(all_args);
	if (nbr_checking(args_aux->args_raw))
		return (-1);
	args_aux->argc = ft_mtxlen(args_aux->args_raw);
	return (0);
}

static int	nbr_checking(char **splitted_args)
{
	if (nbr_validation(splitted_args))
	{
		ft_destroy_matrix((splitted_args));
		splitted_args = NULL;
		return (-1);
	}
	return (0);
}

static void	join_args(char **actual_args, char *new_arg, int index)
{
	char	*temp;

	if (index != 0)
	{
		temp = *actual_args;
		*actual_args = ft_strjoin(temp, " ");
		free(temp);
	}
	temp = *actual_args;
	*actual_args = ft_strjoin(temp, new_arg);
	free(temp);
}

static int	nbr_validation(char **args)
{
	int			i;
	int			j;
	char		*check_str;
	long long	nbr;

	if (args)
	{
		i = 0;
		while (args[i])
		{
			nbr = ft_atoi_llong(args[i]);
			if (nbr > INT_MAX || nbr < INT_MIN)
				return (-1);
			j = i + 1;
			check_str = args[i];
			while (args[j])
			{
				if (ft_strncmp(args[j], check_str, 100) == 0)
					return (-1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

static int	check_invalid_arg(char *raw_arg, char **arg)
{
	char	**check_args;
	int		i;

	if (str_spaced(raw_arg))
	{
		check_args = ft_split(raw_arg, ' ');
		i = 0;
		while (check_args[i])
		{
			if (!valid_number(check_args[i]))
			{
				ft_destroy_matrix(check_args);
				return (-1);
			}
			i++;
		}
		ft_destroy_matrix(check_args);
	}
	else
	{
		if (!valid_number(raw_arg))
			return (-1);
	}
	*arg = ft_strdup(raw_arg);
	return (0);
}
