/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:23:45 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/12 17:23:47 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

int	is_complete(t_stack *a, t_stack *b)
{
	int		idx;
	t_node	*temp;

	if (!is_stack_empty(b))
		return (0);
	idx = 0;
	temp = a->top;
	while (++idx < a->arg_num)
	{
		if (temp->num > temp->prev->num)
			return (0);
		temp = temp->prev;
	}
	return (1);
}

int	count_input(int argc, char *argv[], int *total, int *e)
{
	int		is_in_word;
	int		count;
	char	*str;

	while (0 < --argc)
	{
		count = 0;
		is_in_word = 0;
		str = argv[argc];
		while (*str)
		{
			if (!is_in_word && *str != ' ')
			{
				count++;
				is_in_word = 1;
			}
			else if (is_in_word && *str == ' ')
				is_in_word = 0;
			str++;
		}
		if (count == 0)
			*e = PS_ERR_WRONG_INPUT;
		*total += count;
	}
	return (0);
}

int	*make_input_arr(int total, t_sort **arr, int *e)
{
	*arr = (t_sort *)malloc(sizeof(t_sort) * total);
	if (*arr == 0)
		*e = PS_ERR_MALLOC;
	return (0);
}

int	assign_input_arr(int argc, char *argv[], t_sort *arr, int *e)
{
	int		is_in_word;
	int		count;
	int		idx;
	char	*str;

	count = 0;
	idx = 0;
	while (++idx < argc && *e == 0)
	{
		is_in_word = 0;
		str = argv[idx];
		while (*str)
		{
			if (!is_in_word && *str != ' ')
			{
				is_in_word = 1;
				arr[count++].num[0] = atoi_or_exit(str, e);
			}
			else if (is_in_word && *str == ' ')
				is_in_word = 0;
			str++;
		}
	}
	return (0);
}

int	stack_a_initialize(t_stack *a, t_sort *arr, int total, int *e)
{
	while (0 <= --total && *e == 0)
		insert_stack(a, arr[total].num[0], arr[total].num[2], e);
	return (0);
}
