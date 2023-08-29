/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:11:24 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/07 12:18:28 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(t_list_stk **lst)
{
	free_stack(lst);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

size_t	strlen_2(char **s)
{
	size_t	l;

	l = 0;
	if (!s)
		return (0);
	while (s[l])
		l++;
	return (l);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (1);
	return (0);
}

int	has_space(char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (ft_isspace(s[i]))
			return (1);
		i++;
	}
	return (0);
}

size_t	stack_size(t_list_stk *stack)
{
	size_t	size;

	size = 0;
	while (stack != NULL)
	{
		stack = stack -> next;
		size ++;
	}
	return (size);
}
