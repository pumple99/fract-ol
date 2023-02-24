/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:15:52 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/22 14:15:55 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_mandelbrot_color(int x, int y, t_all *all)
{
	int		re;
	t_coord	c;

	re = -1;
	c.a = (x - all->pos.mid_x) / all->pos.accum + all->pos.mid_realx;
	c.b = (y - all->pos.mid_y) / all->pos.accum + all->pos.mid_realy;
	c.x0 = c.a;
	c.y0 = c.b;
	while (++re < MAX_RECURSION)
	{
		if (c.x0 * c.x0 + c.y0 * c.y0 > 4)
			break ;
		c.x1 = c.x0 * c.x0 - c.y0 * c.y0 + c.a;
		c.y1 = 2 * c.x0 * c.y0 + c.b;
		c.x0 = c.x1;
		c.y0 = c.y1;
	}
	return (create_trgb(50, re * 8, re * 8, re * 8));
}

int	get_julia_color(int x, int y, t_all *all)
{
	int		re;
	t_coord	c;

	re = -1;
	c.a = all->real;
	c.b = all->imaginary;
	c.x0 = (x - all->pos.mid_x) / all->pos.accum + all->pos.mid_realx;
	c.y0 = (y - all->pos.mid_y) / all->pos.accum + all->pos.mid_realy;
	while (++re < MAX_RECURSION)
	{
		if (c.x0 * c.x0 + c.y0 * c.y0 > 4)
			break ;
		c.x1 = c.x0 * c.x0 - c.y0 * c.y0 + c.a;
		c.y1 = 2 * c.x0 * c.y0 + c.b;
		c.x0 = c.x1;
		c.y0 = c.y1;
	}
	return (create_trgb(50, re * 8, re * 8, re * 8));
}
