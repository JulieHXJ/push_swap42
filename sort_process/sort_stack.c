/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:02:14 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/11 01:07:11 by junjun           ###   ########.fr       */
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

void    counting_sort(int *arr, int len, int exp)
{
    int output[len];
    int count[10] = {0};
    int i;
    int digit;
    
    i = 0;
    while (i < len)
    {
        digit = (arr[i] / exp) % 10;
        count[digit]++;
        i++;
    }
    i = 1;
    while (i < 10)
    {
        count[i] += count[i - 1];
        i++;
    }
    i = len - 1;
    while (i >= 0)
    {
        digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
        i--;
    }
    i = 0;
    while (i < len)
        arr[i++] = output[i++];
    
}

void    radix_sort(int *arr, int len)
{
    int exp;
    int max;
    int range;

    exp = 1;
    max = 0;
    while (*arr)
    {
        if (max < *arr)
            max = *arr;
        arr++;
    }
    while (max / exp > 0)
    {
        counting_sort(arr, len, exp);
        exp *= 10;
    }
}