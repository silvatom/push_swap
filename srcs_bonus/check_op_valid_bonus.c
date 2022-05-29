/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_valid_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:46:25 by anjose-d          #+#    #+#             */
/*   Updated: 2022/05/29 19:01:38 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_op_sx(char *input);
static int	check_op_px(char *input);
static int	check_op_rx(char *input);
static int	check_op_rrx(char *input);

int	check_valid_op(char *input)
{
	if (!(check_op_sx(input) || check_op_px(input)
			|| check_op_rx(input) || check_op_rrx(input)))
		return (-1);
	return (0);
}

static int	check_op_sx(char *input)
{
	if (ft_strncmp(input, "sa\n", ft_strlen(input)) == 0)
		return (1);
	if (ft_strncmp(input, "sb\n", ft_strlen(input)) == 0)
		return (1);
	if (ft_strncmp(input, "ss\n", ft_strlen(input)) == 0)
		return (1);
	return (0);
}

static int	check_op_px(char *input)
{
	if (ft_strncmp(input, "pa\n", ft_strlen(input)) == 0)
		return (1);
	if (ft_strncmp(input, "pb\n", ft_strlen(input)) == 0)
		return (1);
	return (0);
}

static int	check_op_rx(char *input)
{
	if (ft_strncmp(input, "ra\n", ft_strlen(input)) == 0)
		return (1);
	if (ft_strncmp(input, "rb\n", ft_strlen(input)) == 0)
		return (1);
	if (ft_strncmp(input, "rr\n", ft_strlen(input)) == 0)
		return (1);
	return (0);
}

static int	check_op_rrx(char *input)
{
	if (ft_strncmp(input, "rra\n", ft_strlen(input)) == 0)
		return (1);
	if (ft_strncmp(input, "rrb\n", ft_strlen(input)) == 0)
		return (1);
	if (ft_strncmp(input, "rrr\n", ft_strlen(input)) == 0)
		return (1);
	return (0);
}
