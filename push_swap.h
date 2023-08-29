/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:40:35 by tponnusa          #+#    #+#             */
/*   Updated: 2023/03/04 17:43:23 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list_stack
{
	int					data;
	int					index;
	struct s_list_stack	*next;
}t_list_stk;

size_t		stack_size(t_list_stk *stack);
t_list_stk	*create_node(t_list_stk *ptr, int data);
t_list_stk	*get_lowest(t_list_stk *stack);
t_list_stk	*get_node(t_list_stk *stack, int index);
int			get_top_data(t_list_stk *stack);
int			get_bottom_data(t_list_stk *stack);

void		push(t_list_stk **src, t_list_stk **tgt);
void		push_a(t_list_stk **s_b, t_list_stk **s_a);
void		push_b(t_list_stk **s_a, t_list_stk **s_b);
void		swap(t_list_stk **stack);
void		swap_stack(t_list_stk **stack, int c);
void		rotate(t_list_stk **stack);
void		rotate_stack(t_list_stk **stack, int c);
void		rotate_reverse(t_list_stk **stack);
void		rotate_reverse_stack(t_list_stk **stack, int c);

void		sort(t_list_stk **stk_a, t_list_stk **stk_b);
void		sort_radix(t_list_stk **stk_a, t_list_stk **stk_b, int size);

int			is_sorted(t_list_stk *stk_a);
void		init_indexes(t_list_stk *stk_a);
void		assign_index(t_list_stk **stk_a);

void		exit_error(t_list_stk **lst);
size_t		strlen_2(char **s);
int			ft_isspace(int c);
void		free_stack(t_list_stk **stackptr);
int			has_space(char *s);
int			is_number(char *s);
int			check_int_limit(long num);

long		push_swap_atoi(const char *str);

#endif