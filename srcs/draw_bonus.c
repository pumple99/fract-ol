/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:34:06 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/22 14:34:08 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"
#include "../mlx/mlx.h"

void	draw_fractal_bonus(t_all *all)
{	
	init_draw_frac(all);
	if (all->type == mandelbrot)
		all->func = get_mandelbrot_color;
	else if (all->type == julia)
		all->func = get_julia_color;
	else
		all->func = get_bonus_color;
	mlx_hook(all->win_ptr, 2, 0, key_down, all);
	mlx_hook(all->win_ptr, 3, 0, key_up, all);
	mlx_hook(all->win_ptr, 4, 0, mouse_hook, all);
	mlx_hook(all->win_ptr, 17, 0, destroy, all);
	mlx_loop_hook(all->mlx_ptr, render_frame, all);
	mlx_loop(all->mlx_ptr);
}
