/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:31 by junjun            #+#    #+#             */
/*   Updated: 2024/12/15 18:15:26 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*to_arr(t_stack *a)
{
	int	*arr;
	int	len;
	int	i;

	len = stack_length(a);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	i = 0;
	while (a)
	{
		arr[i++] = a->data;
		a = a->next;
	}
	return (arr);
}

int	*sort_arr(t_stack *a, int len)
{
	int	*arr;
	int	temp;
	int	i;

	i = 0;
	arr = to_arr(a);
	while (i < len - 1)
	{
		if (arr[i] <= arr[i + 1])
			i++;
		else
		{
			temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = 0;
		}
	}
	return (arr);
}

static bool	above_median(t_stack *stack, t_stack *node)
{
	int		position;
	int		len;
	t_stack	*temp;

	position = 0;
	len = stack_length(stack);
	temp = stack;
	while (temp)
	{
		if (temp == node)
			break ;
		position++;
		if (position > len / 2)
			return (false);
		temp = temp->next;
	}
	return (true);
}

/*
to move the node to the top of the stack for pushing
*/
void	to_top(t_stack **stack, t_stack *node)
{
	if (!*stack || !node)
		return ;
	while (*stack != node)
	{
		if (above_median(*stack, node))
			ra(stack, false);
		else
			rra(stack, false);
	}
}
