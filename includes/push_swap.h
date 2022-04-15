/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:42:46 by anjose-d          #+#    #+#             */
/*   Updated: 2022/04/15 18:57:22 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

#define TRUE 1
#define FALSE 0

int	arg_check(int argc, char *argv[], char ***splitted_args);

/* UTILS */
int	str_spaced(char *str);
int	valid_number(char *str);

#endif