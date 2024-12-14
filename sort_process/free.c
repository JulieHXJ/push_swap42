/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:34:49 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/13 00:35:32 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
	
void error_handling(t_stack *a)
{
	
	exit(EXIT_FAILURE);
}



void free_stack(t_stack *a)
{
	t_stack *temp;
	while (a)
	{
		temp = a;
		a = a->next;
		free(temp);
	}
	free(a);
}


