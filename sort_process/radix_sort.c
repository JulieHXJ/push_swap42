/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:50:25 by junjun            #+#    #+#             */
/*   Updated: 2024/12/12 23:25:13 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



/*
calculate the steps for each node to be on top
*/

void	get_position()
{
	
}

void	get_cost(t_stack *a, t_stack *b, int len_a, int len_b)
{
	t_stack *temp = a;
	int i;
	
	i = 0;
	while (temp)
	{
		if (i < len_a / 2)
		{
			//how many ra to move
			temp->push_cost = i;
		}
		else
		{
			//how many rra to move
			temp->push_cost = len_a - i;
		}
		if (temp->index < len_a / 2)
		{
			temp->above_med = true;
		}
		else
		{
			temp->above_med = false;
		}
		temp = temp->next;
		i++;
	}
	
}

t_stack	*cheapest_node(t_stack *stack)
{
	t_stack *temp;
	t_stack *cheapest;

	temp = stack;
	cheapest = temp;
	while (temp)
	{
		if ((temp->push_cost) < (cheapest->push_cost))
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}

void	push_cheapest(t_stack **a, t_stack **b)
{
	t_stack *cheapest;

	cheapest = cheapest_node(*a);
	while (*a != cheapest)
	{
		if (/* condition */)
		{
			/* code */
		}
		
	}
	
}
