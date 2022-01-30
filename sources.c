/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:05:02 by elerika           #+#    #+#             */
/*   Updated: 2022/01/30 14:26:00 by elerika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isspace(int  c)
{
    c = (unsigned char)c;
    if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' || c == ' ')
        return (1);
    return (0);
}

int ft_atoi(const char *str)
{
    int res;
    int sign;
    int i;
    
    i = 0;
    res = 0;
    sign = 1;
    if (!str)
        return (0);
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-')
    {
        sign = - 1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        res = (res * 10) + (str[i++] - '0');
    return (res * sign);
}

int ft_strncmp(const char   *s1, const char *s2, size_t n)
{
    size_t  i;
    
    i = 0;
    if (n == 0)
        return (0);
    while (s1[i] && s1[i] == s2[i] && i < n - 1)
        i++;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int ft_max(int size_a, int size_b)
{
	if (size_a < size_b)
	{
		return (size_b);
	}
	return (size_a);
}

void ft_show_numbers(int *stack_a, int *stack_b, int size_a, int size_b)
{
	int i;
	int max_variable;

	i = 0;
	max_variable = ft_max(size_a, size_b);
	while (i < max_variable)
	{
		if (size_a > i)
			printf("%d ", stack_a[i]);
		else
			printf("  ");
		if (size_b > i)
			printf("%d ", stack_b[i]);
		printf("\n");
		i++;
	}
	printf("- -\n");
	printf("a b\n");
}