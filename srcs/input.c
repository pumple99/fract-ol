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
#include "../libft/libft.h"

void	erase_nl(char *in)
{
	size_t	len;

	len = ft_strlen(in);
	if (len == 0)
		return ;
	else
	{
		if (in[len - 1] == '\n')
			in[len - 1] = 0;
	}
}

int	count_argu_num(char **in_arr)
{
	int	count;

	count = 0;
	if (!in_arr)
		return (0);
	while (in_arr[count])
		count++;
	return (count);
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

int	is_int(const char *str)
{
	int			index;
	long long	num;	

	index = 0;
	if (str[0] == '-' || str[0] == '+')
		index++;
	if (is_wrong_input(str + index))
		return (0);
	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (num == 0 && str[1] != 0)
		return (0);
	return (1);
}
