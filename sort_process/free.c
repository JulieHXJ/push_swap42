/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:34:49 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/15 15:15:06 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_arr(int *arr)
{
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

void	free_stack(t_stack *a)
{
	t_stack	*temp;

	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
}

void	error_free(t_stack *a, t_stack *b)
{
	ft_printf("Error\n");
	if (a)
	{
		free_stack(a);
	}
	if (b)
	{
		free_stack(b);
	}
	exit(EXIT_FAILURE);
}
