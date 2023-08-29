/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:14:07 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/02 17:41:29 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_stk	*create_node(t_list_stk *next, int data)
{
	t_list_stk	*node;

	node = malloc(sizeof(t_list_stk));
	if (!node)
		return (NULL);
	node -> data = data;
	node -> next = next;
	return (node);
}

t_list_stk	*get_node(t_list_stk *stack, int index)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (i == index)
			return (stack);
		stack = stack -> next;
		i++;
	}
	return (NULL);
}

int	get_top_data(t_list_stk *stack)
{
	if (!stack)
		return (0);
	return (stack -> data);
}

int	get_bottom_data(t_list_stk *stack)
{
	t_list_stk	*last;

	if (!stack)
		return (0);
	last = get_node(stack, (stack_size(stack) - 1));
	return (last->data);
}

void	free_stack(t_list_stk **stackptr)
{
	t_list_stk	*tmp;

	tmp = *stackptr;
	while (tmp)
	{
		tmp = (*stackptr)-> next;
		free(*stackptr);
		*stackptr = tmp;
	}
	free(*stackptr);
}
