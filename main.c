/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:35:26 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/15 21:04:36 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack)
{
    printf("Stack contents:\n");
    while (stack)
    {
        printf("Node: %p, Data: %d, Prev: %p, Next: %p\n",
               stack, stack->data, stack->prev, stack->next);
        stack = stack->next;
    }
    printf("\n");
}


int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (ac <= 1 || !*av[1])
		return (ft_printf("Error\n"), -1);
	else if (ac == 2)
		a = split_to_stack(av[1], ' ');
	else
		args_to_stack(&a, av);
	len = stack_length(a);
	if (!is_sorted(a))
	{
		if (len < 6)
			sort_five(&a, &b);
		else
			radix_sort(&a, &b, len);
	}

	// printf("Final stack A:\n");
    // print_stack(a);
    // printf("Final stack B:\n");
    // print_stack(b);
	
	free_stack(a);
	return (0);
}
