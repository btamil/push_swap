/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:11:24 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/02 17:02:01 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list_stk **src, t_list_stk **tgt)
{
	t_list_stk	*tmp_src;
	t_list_stk	*tmp_tgt;

	if (!(*src))
		return ;
	tmp_src = (*src)-> next;
	tmp_tgt = *tgt;
	*tgt = *src;
	(*tgt)-> next = tmp_tgt;
	(*src) = tmp_src;
}

void	swap(t_list_stk **stack)
{
	t_list_stk	*oldstk;
	t_list_stk	*newstk;

	if (stack_size(*stack) < 2)
		return ;
	oldstk = *stack;
	newstk = (*stack)-> next;
	(*stack)-> next = (*stack)-> next -> next;
	(*stack) = newstk;
	(*stack)-> next = oldstk;
}

void	rotate(t_list_stk **stack)
{
	t_list_stk	*tmp;
	t_list_stk	*head;

	head = *stack;
	tmp = head;
	if (!tmp || !(tmp -> next))
		return ;
	*stack = head -> next;
	while (tmp -> next != NULL)
		tmp = tmp-> next;
	tmp -> next = head;
	head -> next = NULL;
}

void	rotate_reverse(t_list_stk **stack)
{
	t_list_stk	*tmp;
	t_list_stk	*head;
	t_list_stk	*tail;

	head = *stack;
	tmp = head;
	if (!tmp || !(tmp -> next))
		return ;
	while (tmp -> next != NULL)
	{
		if (tmp -> next -> next == NULL)
			tail = tmp;
		tmp = tmp-> next;
	}
	tail -> next = NULL;
	tmp -> next = head;
	*stack = tmp;
}
