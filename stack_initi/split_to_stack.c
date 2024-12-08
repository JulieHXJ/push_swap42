/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xhuang <xhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:22:37 by xhuang            #+#    #+#             */
/*   Updated: 2024/12/08 14:45:31 by xhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *s, char c)
{
	int	wc;
	int	sign;

	wc = 0;
	sign = 0;
	while (*s)
	{
		if (*s != c && sign != 1)
		{
			wc++;
			sign = 1;
		}
		else if (*s == c)
			sign = 0;
		s++;
	}
	return (wc);
}

static char	*get_next_word(char *s, char c)
{
	char		*word;
	int			len;
	static int	i = 0;
	int			j;

	len = 0;
	j = 0;
	while (s[i] == c)
	{
		++i;
	}
	while (s[i + len] && (s[i + len] != c))
	{
		++len;
	}
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
	{
		return (NULL);
	}
	while (s[i] && s[i] != c)
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

/*
spliting the input string into stack a.
*/
t_stack_node	*split_to_stack(char *s, char c)
{
	t_stack_node	*stack;
	int				wc;
	int				i;
	int				data;
	char			word;

	stack = NULL;
	wc = word_count(s, c);
	i = 0;
	while (i < wc)
	{
		word = get_next_word(s, c);
		if (!word)
		{
			return (NULL);
		}
		data = ft_atol(word);
		free(word);
		append_node(&stack, data);
		i++;
	}
	return (stack);
}
