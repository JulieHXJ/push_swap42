/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:35:26 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/16 19:34:59 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (ac <= 1 || !*av[1])
		return (0);
	else if (ac == 2)
		a = split_to_stack(av[1], ' ');
	else
		args_to_stack(&a, av);
	len = stack_length(a);
	if (!is_sorted(a))
	{
		if (len < 20)
			insert_sort(&a, &b);
		else
		{
			ksort_to_b(&a, &b, len);
			ksort_to_a(&a, &b);
		}
	}
	free_stack(a);
	return (0);
}
