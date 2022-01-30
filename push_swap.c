/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 16:03:25 by elerika           #+#    #+#             */
/*   Updated: 2022/01/30 14:24:01 by elerika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define DEBUG 0

int ft_a_sorted(int *stack, int size)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] < stack[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}

int ft_num_pos(int *stack, int element)
{
	int i;

	i = 0;
	while (stack[i] != element)
	{
		i++;
	}
	return (i);
}

int ft_first_num(int chunk, int *stack, int size)
{
	int num;
	int i;

	if (chunk == 1)
	{
		for(i = 0; i < size; i++)
		{
			for(num = 0; num < 20; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	if (chunk == 2)
	{
		for(i = 0; i < size; i++)
		{
			for(num = 20; num < 40; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	if (chunk == 3)
	{
		for(i = 0; i < size; i++)
		{
			for(num = 40; num < 60; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	if (chunk == 4)
	{
		for(i = 0; i < size; i++)
		{
			for(num = 60; num < 80; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	if (chunk == 5)
	{
		for(i = 0; i < size; i++)
		{
			for(num = 80; num < 100; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	return (-1);
}

int ft_second_num(int chunk, int *stack, int size)
{
	int num;
	int i;

	if (chunk == 1)
	{
		for(i = size; i > 0; i--)
		{
			for(num = 0; num < 20; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	if (chunk == 2)
	{
		for(i = size; i > 0; i--)
		{
			for(num = 20; num < 40; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	if (chunk == 3)
	{
		for(i = size; i > 0; i--)
		{
			for(num = 40; num < 60; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	if (chunk == 4)
	{
		for(i = size; i > 0; i--)
		{
			for(num = 60; num < 80; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	if (chunk == 5)
	{
		for(i = size; i > 0; i--)
		{
			for(num = 80; num < 100; num++)
			{
				if(stack[i] == num)
				{
					return (i);
				}
			}
		}
	}
	return (-1);
}

void ft_push(int *source, int *destination, int *size_source, int *size_destination)
{
	int i;

	if (*size_source == 0)
	{
		return;
	}
	*size_destination = *size_destination + 1;
	i = *size_destination;
	while (0 < i)
	{
		destination[i] = destination[i - 1];
		i--;
	}
	destination[0] = source[0];
	i = 0;
	while (i < *size_source)
	{
		source[i] = source[i + 1];
		i++;
	}
	*size_source = *size_source - 1;
}

void ft_swap(int *stack, int size)
{
	int aux;

	if (size <= 1)
	{
		return;
	}
	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
}

void ft_rotate(int *stack, int size)
{
	int aux;
	int i;

	if (size <= 1)
	{
		return;
	}
	aux = stack[0];
	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[size - 1] = aux;
}

void ft_reverse_rotate(int *stack, int size)
{
	int aux;
	int i;

	if (size <= 1)
	{
		return;
	}
	aux = stack[size - 1];
	i = size;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = aux;
}

int ft_lowest(int *stack, int size)
{
	int lowest;
	int i;

	lowest = 2147483647;
	for (i = 0; i < size; i++)
	{
		if (stack[i] < lowest)
			lowest = stack[i];
	}
	return (lowest);
}

void ft_lowest_top(int *stack, int size, int lowest)
{
	if (size == 0)
	{
		return;
	}
	else if (lowest == stack[0])
	{
		return;
	}
	if (ft_num_pos(stack, lowest) > size / 2)
	{
		while (lowest != stack[0])
		{
			ft_reverse_rotate(stack, size);
			printf("rra\n");
		}
	}
	else
	{
		while (lowest != stack[0])
		{
			ft_rotate(stack, size);
			printf("ra\n");
		}
	}
}

void ft_simple_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	while (ft_a_sorted(stack_a, *size_a) == 0)
	{
		ft_lowest_top(stack_a, *size_a, ft_lowest(stack_a, *size_a));
		ft_push(stack_a, stack_b, size_a, size_b);
		printf("pb\n");
	}
	// while (*size_a != 0)
	// {
	// 	ft_lowest_top(stack_a, *size_a, ft_lowest(stack_a, *size_a));
	// 	ft_push(stack_a, stack_b, size_a, size_b);
	// 	printf("pb\n");
	// }
	while (*size_b != 0)
	{
		ft_push(stack_b, stack_a, size_b, size_a);
		printf("pa\n");
	}
}

void ft_better_sort(int *stack_a, int *stack_b, int *size_a, int *size_b)
{
	int chunk;
	int hold_first;
	int hold_second;
	int i;

	while (!ft_a_sorted(stack_a, *size_a))
	{
		for(chunk = 1; chunk < 6; )
		{
			hold_first = ft_first_num(chunk, stack_a, *size_a);
			hold_second = ft_second_num(chunk, stack_a, *size_a);
			if (hold_first == -1 || hold_second == -1)
			{
				chunk++;
			}
			else if (hold_first < (*size_a - hold_second))
			{
				for(i = 0; i < hold_first; i++)
					ft_rotate(stack_a, *size_a);
				ft_lowest_top(stack_b, *size_b, ft_lowest(stack_b, *size_b));
				ft_push(stack_a, stack_b, size_a, size_b);
			}
			else
			{
				for(i = 0; i < hold_first; i++)
					ft_reverse_rotate(stack_a, *size_a);
				ft_lowest_top(stack_b, *size_b, ft_lowest(stack_b, *size_b));
				ft_push(stack_a, stack_b, size_a, size_b);
			}
		}
	}
	while (*size_b != 0)
	{
		ft_push(stack_b, stack_a, size_b, size_a);
	}
}

void ft_allocate_and_sort(char **numbers, int n_elements)
{
	int i;

	int *stack_a;
	int *stack_b;
	int size_a;
	int size_b;

	stack_a = (int *)malloc(n_elements * sizeof(int));
	stack_b = (int *)malloc(n_elements * sizeof(int));

	size_a = n_elements;
	size_b = 0;

	i = 0;
	while (i < n_elements)
	{
		stack_a[i] = ft_atoi(numbers[i + 1]);
		i++;
	}
	// ft_simple_sort(stack_a, stack_b, &size_a, &size_b);
	ft_better_sort(stack_a, stack_b, &size_a, &size_b);
	ft_show_numbers(stack_a, stack_b, size_a, size_b);

	// free(stack_a);
	// free(stack_b);
}

int main(int argc, char **argv)
{
	int n_elements;

	if (argc == 1)
	{
		exit(1);
	}

	n_elements = argc - 1;
	ft_allocate_and_sort(argv, n_elements);

	return 0;
}

// int main(int argc, char **argv)
// {
// 	int n_elements;
// 	int *a;
// 	int *b;
// 	int size_a;
// 	int size_b;
// 	int i;
// 	char commands[4];

// 	if (argc == 1)
// 	{
// 		printf("Oh no, we have only 1 parameter!\n");
// 		exit(1);
// 	}

// 	n_elements = argc - 1;
// 	a = malloc(n_elements * sizeof(int));
// 	b = malloc(n_elements * sizeof(int));
// 	size_a = n_elements;
// 	size_b = 0;

// 	i = 0;
// 	while (i < n_elements)
// 	{
// 		a[i] = ft_atoi(argv[i + 1]);
// 		i++;
// 	}
// 	ft_simple_sort(a, b, &size_a, &size_b);
// 		return (0);
// 	while (1)
// 	{
// 		scanf("%s", commands);
// 		if (!ft_strncmp(commands, "sa", 2))
// 		{
// 			ft_swap(a, size_a);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "sb", 2))
// 		{
// 			ft_swap(b, size_b);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "ss", 2))
// 		{
// 			ft_swap(a, size_a);
// 			ft_swap(b, size_b);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "pa", 2))
// 		{
// 			ft_push(b, a, &size_b, &size_a);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "pb", 2))
// 		{
// 			ft_push(a, b, &size_a, &size_b);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "ra", 2))
// 		{
// 			ft_rotate(a, size_a);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "rb", 2))
// 		{
// 			ft_rotate(b, size_b);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "rra", 3))
// 		{
// 			ft_reverse_rotate(a, size_a);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "rrb", 3))
// 		{
// 			ft_reverse_rotate(b, size_b);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "rrr", 3))
// 		{
// 			ft_reverse_rotate(a, size_a);
// 			ft_reverse_rotate(b, size_b);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "rr", 2))
// 		{
// 			ft_rotate(a, size_a);
// 			ft_rotate(b, size_b);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "ll", 2))
// 		{
// 			ft_lowest_top(a, size_a, ft_lowest(a, size_a));
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "l", 1))
// 		{
// 			ft_lowest(a, size_a);
// 			printf("%d\n", ft_lowest(a, size_a));
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 		else if (!ft_strncmp(commands, "s", 1))
// 		{
// 			ft_simple_sort(a, b, &size_a, &size_b);
// 			if (DEBUG)
// 				ft_show_numbers(a, b, size_a, size_b);
// 		}
// 	}
// 	return (0);
// }