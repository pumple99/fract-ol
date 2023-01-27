#include <mlx.h>
#include <math.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
	return (create(trgb(100, re * 8, re * 8, re * 8)));
}

void	draw_mandelbrot(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x;
	int		y;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Mandelbrot");
	img.img = mlx_new_image(mlx, 1200, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, img.line_length, \
	&img.endian);
	x = -1;
	y = -1;
	while (++x < 1200)
	{
		while (++y < 800)
			my_mlx_pixel_put(&img, x, y, get_mandelbrot_color(x, y));
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 320, 140);
	mlx_loop(mlx);
}
