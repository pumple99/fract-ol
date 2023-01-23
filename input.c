/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:21:47 by seunghoy          #+#    #+#             */
/*   Updated: 2023/01/06 20:55:55 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft/libft.h"
#include "push_swap.h"

static void	arr_swap(t_sort *arr, int a, int b)
{
	t_sort	temp;

	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

static void	quick(t_sort *arr, int l, int r, int sort_std)
{
	int	left;
	int	right;
	int	pivot;

	left = l;
	right = r;
	pivot = arr[(l + r) / 2].num[sort_std];
	while (left <= right)
	{
		while (arr[left].num[sort_std] < pivot)
			left++;
		while (arr[right].num[sort_std] > pivot)
			right--;
		if (left <= right)
		{
			arr_swap(arr, left, right);
			left++;
			right--;
		}
	}
	if (l < right)
		quick(arr, l, right, sort_std);
	if (left < r)
		quick(arr, left, r, sort_std);
}

int	find_idx_check_dup(int total, t_sort *arr, int *e)
{
	int	idx;

	idx = -1;
	while (++idx < total)
		arr[idx].num[1] = idx;
	quick(arr, 0, total - 1, 0);
	idx = -1;
	while (++idx < total - 1)
	{
		if (arr[idx].num[0] == arr[idx + 1].num[0])
		{
			*e = PS_ERR_DUPLICATE_INPUT;
			return (*e);
		}
		arr[idx].num[2] = idx;
	}
	arr[idx].num[2] = idx;
	quick(arr, 0, total - 1, 1);
	return (0);
}

static int	is_wrong_input(const char *str)
{
	int		len;

	len = 0;
	while (str[len] && str[len] != ' ')
	{
		if (str[len] < '0' || '9' < str[len])
			return (1);
		len++;
	}
	if (len == 0 || len > 10)
		return (1);
	return (0);
}

int	atoi_or_exit(const char *str, int *e)
{
	int			index;
	long long	num;	

	index = 0;
	if (str[0] == '-' || str[0] == '+')
		index++;
	if (is_wrong_input(str + index))
		*e = PS_ERR_WRONG_INPUT;
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		*e = PS_ERR_WRONG_INPUT;
	if (num == 0 && (str[0] != '0' || (str[1] != 0 && str[1] != ' ')))
		*e = PS_ERR_WRONG_INPUT;
	return ((int)num);
}
