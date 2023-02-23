/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_man.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:03:06 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/23 17:03:09 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"
#include "mlx/mlx.h"

void	draw_fractal(t_all *all)
{	
	init_draw_frac(all);
	if (all->type == mandelbrot)
		all->func = get_mandelbrot_color;
	else
		all->func = get_julia_color;
	mlx_hook(all->win_ptr, 2, 0, key_down, all);
	mlx_hook(all->win_ptr, 3, 0, key_up, all);
	mlx_hook(all->win_ptr, 4, 0, mouse_hook, all);
	mlx_hook(all->win_ptr, 17, 0, destroy, all);
	mlx_loop_hook(all->mlx_ptr, render_frame, all);
	mlx_loop(all->mlx_ptr);
}
