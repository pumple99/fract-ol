/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:37:25 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/21 18:37:28 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fractal.h"

int	main(void)
{
	char	**in_arr;
	t_all	all;

	in_arr = 0;
	get_frac_argu(&in_arr);
	all.type = parse_input(in_arr);
	if (all.type == invalid)
		return (print_possible_input());
	if (all.type != mandelbrot)
	{
		all.real = ft_atoi(in_arr[1]) / (double)1000000;
		all.imaginary = ft_atoi(in_arr[2]) / (double)1000000;
	}
	free_split_arr(in_arr);
	draw_fractal(&all);
}
