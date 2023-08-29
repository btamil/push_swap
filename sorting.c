/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:40:35 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/07 10:44:41 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	get_position(t_list_stk **s_a)
{
	t_list_stk	*tmp;
	int			index;
	int			minval;

	tmp = (*s_a);
	minval = get_lowest(*s_a)-> data;
	index = 0;
	while (tmp)
	{
		if (tmp -> data == minval)
			break ;
		index ++;
		tmp = tmp -> next;
	}
	return (index);
}

static void	sort_3(t_list_stk **stack)
{
	int	top;
	int	mid;
	int	bot;

	top = get_top_data(*stack);
	mid = get_node(*stack, 1)-> data;
	bot = get_bottom_data(*stack);
	if (top > mid && bot > mid && top < bot)
		swap_stack(stack, 'a');
	else if (top > mid && mid > bot && top > bot)
	{
		swap_stack(stack, 'a');
		rotate_reverse_stack(stack, 'a');
	}
	else if (top > mid && bot > mid && top > bot)
		rotate_stack(stack, 'a');
	else if (top < mid && mid > bot && top > bot)
		rotate_reverse_stack(stack, 'a');
	else if (top < mid && mid > bot && top < bot)
	{
		swap_stack(stack, 'a');
		rotate_stack(stack, 'a');
	}
}

static void	sort_4(t_list_stk **s_a, t_list_stk **s_b)
{
	int	pos;

	pos = get_position(s_a);
	if (pos == 1)
		rotate_stack(s_a, 'a');
	else if (pos == 2)
	{
		rotate_stack(s_a, 'a');
		rotate_stack(s_a, 'a');
	}
	else if (pos == 3)
		rotate_reverse_stack(s_a, 'a');
	push_b(s_a, s_b);
	sort_3(s_a);
	push_a(s_b, s_a);
}

static void	sort_5(t_list_stk **s_a, t_list_stk **s_b)
{
	int	pos;

	pos = get_position(s_a);
	if (pos == 1)
		rotate_stack(s_a, 'a');
	else if (pos == 2)
	{
		rotate_stack(s_a, 'a');
		rotate_stack(s_a, 'a');
	}
	else if (pos == 3)
	{
		rotate_reverse_stack(s_a, 'a');
		rotate_reverse_stack(s_a, 'a');
	}
	else if (pos == 4)
		rotate_reverse_stack(s_a, 'a');
	push_b(s_a, s_b);
	sort_4(s_a, s_b);
	push_a(s_b, s_a);
}

void	sort(t_list_stk **stk_a, t_list_stk **stk_b)
{
	size_t	size;

	size = stack_size(*stk_a);
	init_indexes(*stk_a);
	if (size == 2)
		swap_stack(stk_a, 'a');
	else if (size == 3)
		sort_3(stk_a);
	else if (size == 4)
		sort_4(stk_a, stk_b);
	else if (size == 5)
		sort_5(stk_a, stk_b);
	else
	{
		assign_index(stk_a);
		sort_radix(stk_a, stk_b, size);
	}
}
