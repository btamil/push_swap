/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:00:56 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/02 20:53:39 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_list_stk **s_b, t_list_stk **s_a)
{
	push(s_b, s_a);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_list_stk **s_a, t_list_stk **s_b)
{
	push(s_a, s_b);
	ft_putstr_fd("pb\n", 1);
}

void	swap_stack(t_list_stk **stack, int c)
{
	if (c == 'a')
	{
		swap(stack);
		ft_putstr_fd("sa\n", 1);
	}
	else if (c == 'b')
	{
		swap(stack);
		ft_putstr_fd("sb\n", 1);
	}
}

void	rotate_stack(t_list_stk **stack, int c)
{
	if (c == 'a')
	{
		rotate(stack);
		ft_putstr_fd("ra\n", 1);
	}
	else if (c == 'b')
	{
		rotate(stack);
		ft_putstr_fd("rb\n", 1);
	}
}

void	rotate_reverse_stack(t_list_stk **stack, int c)
{
	if (c == 'a')
	{
		rotate_reverse(stack);
		ft_putstr_fd("rra\n", 1);
	}
	else if (c == 'b')
	{
		rotate_reverse(stack);
		ft_putstr_fd("rrb\n", 1);
	}
}
