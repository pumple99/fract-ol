/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:12:03 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/23 17:12:04 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h> //errno
#include <stdio.h> //perror
#include <string.h> //strerror
#include "../fractal.h"
#include "../libft/libft.h"
#include "../libft/gnl.h"

void	get_frac_argu(char ***in_arr_p)
{
	char	*in;

	print_possible_input();
	in = get_next_line(0);
	if (in == (char *)1)
	{
		errno = EAGAIN;
		perror(strerror(errno));
		exit(1);
	}
	else if (in == 0)
		exit(print_possible_input());
	else
	{
		erase_nl(in);
		*in_arr_p = ft_split(in, ' ');
		free(in);
	}
}

int	parse_input(char **in_arr)
{
	int	argu_count;

	argu_count = count_argu_num(in_arr);
	if (argu_count == 0)
		return (invalid);
	if (ft_strncmp(in_arr[0], "0", 2) == 0)
		return (mandelbrot);
	if (argu_count < 3 || !is_int(in_arr[1]) || !is_int(in_arr[2]))
		return (invalid);
	if (ft_strncmp(in_arr[0], "1", 2) == 0)
		return (julia);
	return (invalid);
}
