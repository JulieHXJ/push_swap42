/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:34:49 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/16 01:09:51 by junjun           ###   ########.fr       */
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
	ft_putendl_fd("Error", 2);
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
