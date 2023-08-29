/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:35:15 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/02 20:45:25 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_radix(t_list_stk **stk_a, t_list_stk **stk_b, int size)
{
	t_list_stk	*tmp;
	int			digit;
	int			i;

	digit = 0;
	while (!is_sorted(*stk_a))
	{
		i = 0;
		while (i < size)
		{
			tmp = *stk_a;
			if (((tmp -> index >> digit) & 1) == 1)
				rotate_stack(stk_a, 'a');
			else
				push_b(stk_a, stk_b);
			i++;
		}
		while (stack_size(*stk_b))
		{
			push_a(stk_b, stk_a);
		}
		digit++;
	}
}
