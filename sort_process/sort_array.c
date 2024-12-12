/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:31 by junjun            #+#    #+#             */
/*   Updated: 2024/12/12 23:25:13 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int *to_arr(t_stack **a)
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
		arr[i] = (*a)->data;
		*a = (*a)->next;
		i++;
	}
	return (arr);
}

static void    counting_sort(int *arr, int len, int exp)
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

static void    radix_sort(int *arr, int len)
{
    int exp;
    int max;
	int i;
	int origin;

	i = 0;
    max = 0;
	origin = arr[0];
    while (i < len)
    {
		arr[i] = abs(arr[i]);
        if (arr[i] > max)
            max = arr[i];
        i++;
    }
    exp = 1;
    while (max / exp > 0)
    {
        counting_sort(arr, len, exp);
        exp *= 10;
    }
	if (origin < 0)
	{
		i = 0;
		while (i < len)
		{
			arr[i] = -arr[i];
			i++;
		}
	}
}

int	*sort_arr(t_stack *a, int len)
{
	int *arr = to_arr(a);
    int *arr_pos;
    int *arr_neg;
	int pos_len = 0;
	int neg_len = 0;
	int i;
    
	arr_pos = malloc(len * sizeof(int));
	arr_neg = malloc(len * sizeof(int));
	if (!arr_pos || !arr_neg)
		return ;
	i = 0;
	while (i < len)
	{
		if (arr[i] >= 0)
			arr_pos[pos_len++] = arr[i];
		else
			arr_neg[neg_len++] = arr[i];
		i++;
	}
	radix_sort(arr_pos, pos_len);
	if (neg_len > 0)
		radix_sort(arr_neg, neg_len);
	ft_memcpy(arr, arr_neg, (size_t)neg_len);
	ft_memcpy(arr + neg_len, arr_pos, (size_t)pos_len);
    free(arr_neg);
	free(arr_pos);
	return(arr);
}

