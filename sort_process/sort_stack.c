/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:02:14 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/08 17:10:37 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
    int len;
    
    len = stack_length(*a);
    if (len > 3 && !is_sorted(*a))
    {
        //firstly push two node to stack b, 
        pb(a, b);
        pb(a, b);
        //then the rest node base on target and cheapest way
    }
	sort_three(a);
	while (*b)
	{
		//push back to a base on target
        pa(a, b);
	}
	
    
}
