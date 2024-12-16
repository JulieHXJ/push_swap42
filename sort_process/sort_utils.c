/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:08 by junjun            #+#    #+#             */
/*   Updated: 2024/12/16 19:34:34 by xhuang           ###   ########.fr       */
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
	t_stack	*min;

	if (!a)
		return (NULL);
	min = a;
	while (a)
	{
		if (a->data < min->data)
			min = a;
		a = a->next;
	}
	return (min);
}

t_stack	*max_node(t_stack *a)
{
	t_stack	*max;

	if (!a)
		return (NULL);
	max = a;
	while (a)
	{
		if (max->data < a->data)
			max = a;
		a = a->next;
	}
	return (max);
}
