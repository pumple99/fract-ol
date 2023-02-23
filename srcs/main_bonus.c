/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:39:03 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/23 17:39:05 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fractal.h"

int	main(void)
{
	char	**in_arr;
	t_all	all;

	in_arr = 0;
	get_frac_argu_bonus(&in_arr);
	all.type = parse_input_bonus(in_arr);
	if (all.type == invalid)
		return (print_possible_input_bonus());
	if (all.type != mandelbrot)
	{
		all.real = ft_atoi(in_arr[1]) / (double)1000000;
		all.imaginary = ft_atoi(in_arr[2]) / (double)1000000;
	}
	free_split_arr(in_arr);
	draw_fractal_bonus(&all);
}
