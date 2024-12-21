/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:35:26 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/21 19:24:05 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b, int len)
{
	if (len < 20)
		insert_sort(a, b);
	else
	{
		ksort_to_b(a, b, len);
		ksort_to_a(a, b);
	}
}

/*
check if stack a is already in right order
*/
bool	is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a->next;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**word;
	int		len;

	a = NULL;
	b = NULL;
	if (ac <= 1 || !*av[1])
		return (0);
	else if (ac == 2)
	{
		word = ft_split(av[1], ' ');
		if (!word)
			return (0);
		to_stack(&a, word);
		free_str_arr(word);
	}
	else
		to_stack(&a, &av[1]);
	len = stack_length(a);
	if (!is_sorted(a))
		sort_stack(&a, &b, len);
	free_stack(a);
	free_stack(b);
	return (0);
}
