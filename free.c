/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:34:49 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/21 19:13:29 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_int_arr(int *arr)
{
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}

void	free_str_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_stack *a)
{
	t_stack	*temp;

	if (!a)
		return ;
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

/*
 * for ksort
 */
int	square_root(int n)
{
	int	left;
	int	right;
	int	sqr;
	int	mid;

	left = 0;
	right = n;
	sqr = 0;
	if (n < 0)
		return (-1);
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid * mid == n)
			return (mid);
		else if (mid * mid < n)
		{
			sqr = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return (sqr);
}
