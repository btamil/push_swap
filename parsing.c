/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:05:18 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/04 17:41:34 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if ((s[i] == '+' || s[i] == '-') && s[i + 1] != '\0')
		i++;
	while (s[i] && ft_isdigit(s[i]))
		i++;
	if (s[i] != '\0' && !ft_isdigit(s[i]))
		return (0);
	return (1);
}

int	check_int_limit(long num)
{
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}
