/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:22 by junjun            #+#    #+#             */
/*   Updated: 2024/12/13 00:13:25 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*sort_three(t_stack **a)
{
	t_stack	*max;

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

void	*sort_five(t_stack **a, t_stack **b)
{
    t_stack *min;
	
	if (is_sorted(*a))
		return ;
    while (stack_length(a) > 3)
    {
        min = min_node(*a);
        to_top(a, min);
        pb(a, b, false);
    }
	sort_three(a);
    while (stack_length(b) > 0)
       pb(a, b, false);
}

/*
give the target index of stack node base on sorted array
*/
static void	init_index(t_stack *a, int *arr)
{
	int i;
	t_stack *temp;
	int len;

    temp = a;
    len = stack_length(a);
	while (temp)
	{
        i = 0;
		while (i < len)
		{
			if (temp->data == arr[i])
			{
				temp->targ_index = i;
				break;
			}
			i++;
		}
		temp = temp->next;
	}
}

static int   get_max_bits(t_stack *a)
{
    int max_index;
    int max_bits;

    max_index = stack_length(a) - 1;
    max_bits = 0;
    while ((max_index >> max_bits) != 0)
       max_bits++;
    return(max_bits);
}

void	radix_sort(t_stack **a, t_stack **b, int len)
{
    int *arr;
    int max_bits;
    int i;
    
    arr = sort_arr(a);
	init_index(*a, arr);
    max_bits = get_max_bits(a);
    free(arr);
    i = 0;
    while (i < max_bits)
    {
        int j = 0;
        while (j < len)
        {
            if ((((*a)->targ_index >> i) & 1) == 1)
                ra(a, false);
            else
                pb(a, b, false);
            j++;
        }
        while (stack_length(b) > 0)
        {
            pa(a, b, false);
        }
        i++;
    }
}
