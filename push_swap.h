/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:01:15 by elerika           #+#    #+#             */
/*   Updated: 2022/01/30 16:20:11 by elerika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int     ft_atoi(const char *str);
int     ft_strncmp(const char   *s1, const char *s2, size_t n);
void    ft_show_numbers(int *stack_a, int *stack_b, int size_a, int size_b);

#endif