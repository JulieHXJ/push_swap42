/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:22 by junjun            #+#    #+#             */
/*   Updated: 2024/12/11 15:46:24 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*sort_three(t_stack_node **a)
{
	t_stack_node	*max;

	max = max_node(*a);
	if (is_sorted(*a))
		return ;
	if (stack_length(*a) == 2)
		sa(*a, false);
	else if (stack_length(*a) == 3)
	{
		if (max == *a)
			ra(a, false);
		else if (max == (*a)->next)
			rra(a, false);
		if ((*a)->data > (*a)->next->data)
			sa(*a, false);
	}
}

void	*sort_five(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;
	t_stack_node	*max;
	
	if (is_sorted(*a))
		return ;
	pb(a, b, false);
	if (stack_length(a) > 3 && !is_sorted(a))
	{
		pb(a, b, false);
	}
	sort_three(a);
	pa(a, b, false);
   
    if (!is_sorted(a))
    {
        //
    }
	if (stack_length(b) > 0)
	{
		pa(a, b, false);
        if (!is_sorted(a))
        {
            //
        }
        
	}
	
}

void    sort_stack(t_stack_node **a, t_stack_node **b, int *arr)
{
    //sort stack with int array and push to a
}