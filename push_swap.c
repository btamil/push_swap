/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:36:09 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/15 17:13:32 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_create_node(t_list_stk **lst, char *s)
{
	long	num;

	if (!s || !s[0] || !is_number(s))
		exit_error(lst);
	num = push_swap_atoi(s);
	if (!check_int_limit(num))
		exit_error(lst);
	*lst = create_node(*lst, num);
}

static void	check_duplicates(t_list_stk **lst)
{
	t_list_stk	*tmp;
	t_list_stk	*tmp1;

	tmp = *lst;
	if (tmp && (tmp -> next))
	{
		while (tmp)
		{
			tmp1 = tmp -> next;
			while (tmp1)
			{
				if (tmp -> data == tmp1 -> data)
					exit_error(lst);
				tmp1 = tmp1 -> next;
			}
			tmp = tmp -> next;
		}
	}
}

static void	parse_input(t_list_stk **lst, int index, char **av)
{
	int		len;
	char	**strs;

	while (index > 0)
	{
		if (has_space(av[index]))
		{
			strs = ft_split(av[index], ' ');
			if (!strs || strs[0] == NULL)
				exit_error(lst);
			len = strlen_2(strs) - 1;
			while (len >= 0)
			{
				ft_create_node(lst, strs[len]);
				free(strs[len]);
				len--;
			}
			free(strs);
		}
		else
			ft_create_node(lst, av[index]);
		index --;
	}
	check_duplicates(lst);
}

int	main(int ac, char **av)
{
	t_list_stk	*stk_a;
	t_list_stk	*stk_b;
	int			len;

	stk_a = NULL;
	stk_b = NULL;
	len = ac - 1;
	parse_input(&stk_a, len, av);
	if (!is_sorted(stk_a))
		sort(&stk_a, &stk_b);
	free_stack(&stk_a);
	free_stack(&stk_b);
	return (0);
}
