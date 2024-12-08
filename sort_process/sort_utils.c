/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:34:46 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/08 16:09:28 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack_node *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stack_node	*last_node(t_stack_node *a)
{
	while (a && a->next)
		a = a->next;
	return (a);
}

t_stack_node	*min_node(t_stack_node *a)
{
	t_stack_node *min;

	min = a;
	while (a)
	{
		if (min->data > a->data)
			min = a->next;
		a = a->next;
	}
	return (min);
}

t_stack_node	*max_node(t_stack_node *a)
{
	t_stack_node *max;

	max = a;
	while (a)
	{
		if (max->data < a->data)
			max = a->next;
		a = a->next;
	}
	return (max);
}

/*
for stack_length <= 3
*/
void	*sort_three(t_stack_node **a)
{
	t_stack_node	*max;

	max = max_node(*a);
	if (stack_length(*a) == 2)
		sa(*a);
	else if (stack_length(*a) == 3)
	{
		if (max == *a)
			ra(a);
		else if (max == (*a)->next)
			rra(a);
		if ((*a)->data > (*a)->next->data)
			sa(*a);
	}
}
