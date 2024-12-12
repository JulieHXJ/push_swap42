/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:08 by junjun            #+#    #+#             */
/*   Updated: 2024/12/13 00:09:32 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_length(t_stack *a)
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

t_stack	*last_node(t_stack *a)
{
	while (a && a->next)
		a = a->next;
	return (a);
}

t_stack	*min_node(t_stack *a)
{
	t_stack *min;
	long		min_nbr;

	min = NULL;
	min_nbr = LONG_MAX;
	while (a)
	{
		if (a->data < min_nbr)
		{
			min_nbr = a->data;
			min = a;
		}
		a = a->next;
	}
	return (min);
}

t_stack	*max_node(t_stack *a)
{
	t_stack *max;

	max = a;
	while (a)
	{
		if (max->data < a->data)
			max = a;
		a = a->next;
	}
	return (max);
}

bool	above_median(t_stack *stack, t_stack *node)
{
	int	position;
	int	len;
	t_stack	*temp;

	position = 0;
	len = stack_length(stack);
	temp = stack;
	while (temp)
	{
		if (temp == node)
			break;
		position++;
		if (position > len / 2)
			return (false);
		temp = temp->next;
	}
	return (true);
}

void	to_top(t_stack **stack, t_stack *node)
{
	bool	is_above = above_median(stack, node);

	if (is_above)
	{
		while (*stack != node)
			ra(stack, false);
	}
	else
	{
		while (*stack != node)
			rra(stack, false);
	}
}
