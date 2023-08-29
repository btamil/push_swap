/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:53:37 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/07 12:18:14 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list_stk *stack)
{
	while (stack && stack -> next)
	{
		if ((stack -> data) > (stack -> next -> data))
			return (0);
		stack = stack -> next;
	}
	return (1);
}

void	init_indexes(t_list_stk *stack)
{
	while (stack)
	{
		stack -> index = -1;
		stack = stack -> next;
	}
}

t_list_stk	*get_next_index(t_list_stk **stack)
{
	t_list_stk	*tmp;
	t_list_stk	*next_min;
	int			flag;

	flag = 0;
	tmp = *stack;
	next_min = NULL;
	if (tmp)
	{
		while (tmp)
		{
			if ((tmp -> index == -1)
				&& (!flag || (tmp -> data < next_min -> data)))
			{
				next_min = tmp;
				flag = 1;
			}
			tmp = tmp -> next;
		}
	}
	return (next_min);
}

void	assign_index(t_list_stk **stk_a)
{
	t_list_stk	*tmp;
	int			index;

	index = 0;
	tmp = get_next_index(stk_a);
	while (tmp)
	{
		tmp -> index = index;
		tmp = get_next_index(stk_a);
		index++;
	}
}

t_list_stk	*get_lowest(t_list_stk *stack)
{
	t_list_stk	*tmp;

	tmp = stack;
	while (stack)
	{
		if (stack -> data < tmp -> data)
			tmp = stack;
		stack = stack -> next;
	}
	return (tmp);
}
