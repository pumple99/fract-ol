/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:37:04 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/21 18:37:09 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../mlx/mlx.h"
#include "../fractal.h"

static void	move_cam(t_all *all)
{
	if (all->move.left == 1 && all->pos.mid_realx > -5)
		all->pos.mid_realx -= 10 / all->pos.accum;
	if (all->move.right == 1 && all->pos.mid_realx < 5)
		all->pos.mid_realx += 10 / all->pos.accum;
	if (all->move.down == 1 && all->pos.mid_realy < 5)
		all->pos.mid_realy += 10 / all->pos.accum;
	if (all->move.up == 1 && all->pos.mid_realy > -5)
		all->pos.mid_realy -= 10 / all->pos.accum;
}

int	render_frame(t_all *all)
{
	int		x;
	int		y;

	if (++(all->frame) == 16777216)
		all->frame = 0;
	move_cam(all);
	x = -1;
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			my_mlx_pixel_put(&(all->img), x, y, \
			(all->func)(x, y, all) + all->frame);
		}
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img.img_ptr, 0, 0);
	return (0);
}

void	init_draw_frac(t_all *all)
{
	all->mlx_ptr = mlx_init();
	all->win_ptr = mlx_new_window(all->mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "Fract-ol");
	all->img.img_ptr = mlx_new_image(all->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	all->img.addr = mlx_get_data_addr(all->img.img_ptr, \
	&(all->img.bits_per_pixel), &(all->img.line_length), &(all->img.endian));
	all->pos.accum = 400.0;
	all->pos.mid_x = WIN_WIDTH / 2;
	all->pos.mid_y = WIN_HEIGHT / 2;
	all->pos.mid_realx = 0;
	all->pos.mid_realy = 0;
	all->move.left = 0;
	all->move.right = 0;
	all->move.down = 0;
	all->move.up = 0;
	all->frame = 0;
}
