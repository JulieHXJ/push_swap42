/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:34:46 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/11 00:55:11 by junjun           ###   ########.fr       */
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
	if (!a)
		return (NULL);
	while (a && a->next)
		a = a->next;
	return (a);
}

t_stack_node	*min_node(t_stack_node *a)
{
	t_stack_node *min;
	long		min_nbr;

	if (!a)
		return (NULL);
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

int *dup_arr(t_stack_node **a)
{
	int *arr;
	int len;
	int i;
	
	i = 0;
	len = stack_length(*a);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (*a)
	{
		arr[i++] = (*a)->data;
		*a = (*a)->next;
	}
	return (arr);
}
