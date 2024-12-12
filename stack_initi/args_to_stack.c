/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junjun <junjun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:46:41 by junjun            #+#    #+#             */
/*   Updated: 2024/12/12 23:25:13 by junjun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *s)
{
	int		sign;
	long	nbr;
	int		i;

	sign = 1;
	nbr = 0;
	i = 0;
	while (s[i] < 33)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= 0 && s[i] <= 9)
	{
		nbr = nbr * 10 + (s[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void	append_node(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*last;

	if (!stack)
		return ;
	new = malloc(sizeof(t_stack) * 1);
	if (!new)
		return ;
	new->next = NULL;
	new->data = n;
	if (!*stack)
	{
		*stack = new;
		new->prev = NULL;
	}
	else
	{
		last = last_node(*stack);
		last->next = new;
		new->prev = last;
	}
}

/*
take arguments to initialize the stack a.
*/
void	args_to_stack(t_stack **a, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (!check_args)
		{
			error free return ;
		}
		nbr = ft_atol(av[i]);
		append_node(a, (int)nbr);
		i++;
	}
}
