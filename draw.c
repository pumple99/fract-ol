#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include "fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_mandelbrot_color(int x, int y)
{
	int		max_re;
	int		accum;
	int		mid_x;
	int		mid_y;
	int		re;
	double	a;
	double	b;
	double	n_x;
	double	n_y;
	double	coord_x;
	double	coord_y;
	
	re = -1;
	mid_x = 800;
	mid_y = 400;
	accum = 400;
	max_re = 30;
	a = (double)(mid_x - x) / accum;
	b = (double)(mid_y - y) / accum;
	coord_x = a;
	coord_y = b;
	while (++re < max_re)
	{
		if (coord_x * coord_x + coord_y * coord_y > 4)
			break;
		n_x = coord_x * coord_x - coord_y * coord_y + a;
		n_y = 2 * coord_x * coord_y + b;
		coord_x = n_x;
		coord_y = n_y;
	}
	return (create_trgb(50, re * 8, re * 8, re * 8));
}

int	key_hook(int keycode, t_temp *all)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	return (0);
}

void	draw_mandelbrot(void)
{
	t_temp	all;
	t_data	img;
	int		x;
	int		y;
	
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, 1920, 1080, "Mandelbrot");
	img.img = mlx_new_image(all.mlx, 1200, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, \
	&img.endian);
	x = -1;
	while (++x < 1200)
	{
		y = -1;
		while (++y < 800)
			my_mlx_pixel_put(&img, x, y, get_mandelbrot_color(x, y));
	}
	mlx_put_image_to_window(all.mlx, all.win, img.img, 320, 140);
	mlx_key_hook(all.win, key_hook, &all);
	mlx_loop(all.mlx);
}
