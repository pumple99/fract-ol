/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:32:13 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/04 20:32:15 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define MAX_RECURSION 30
# define WIN_WIDTH 1200
# define WIN_HEIGHT 1000

typedef struct s_coord
{
	double	a;
	double	b;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	x2;
	double	y2;
}	t_coord;

typedef enum e_frac_type
{
	mandelbrot = 0,
	julia,
	invalid,
	bonus
}	t_frac_type;

typedef struct s_pos
{
	double	accum;
	double	mid_realx;
	double	mid_realy;
	int		mid_x;
	int		mid_y;
}	t_pos;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_move
{
	int	left;
	int	right;
	int	up;
	int	down;
}	t_move;

typedef struct s_all
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_pos		pos;
	int			frame;
	t_frac_type	type;
	t_move		move;
	double		real;
	double		imaginary;
	int			(*func)(int, int, struct s_all *);
}	t_all;

//draw.c
int		render_frame(t_all *all);
void	init_draw_frac(t_all *all);
//_man
void	draw_fractal(t_all *all);
//_bonus
void	draw_fractal_bonus(t_all *all);

//color.c
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
int		get_mandelbrot_color(int x, int y, t_all *all);
int		get_julia_color(int x, int y, t_all *all);
//_bonus
int		get_bonus_color(int x, int y, t_all *all);

//hook.c
int		destroy(t_all *all);
int		key_down(int keycode, t_all *all);
int		key_up(int keycode, t_all *all);
int		mouse_hook(int mousecode, int x, int y, t_all *all);

//print.c
int		print_possible_input(void);
//_bonus
int		print_possible_input_bonus(void);

//input.c
int		count_argu_num(char **in_arr);
int		is_int(const char *str);
void	erase_nl(char *in);
//_man
int		parse_input(char **in_arr);
void	get_frac_argu(char ***in_arr_p);
//_bonus
int		parse_input_bonus(char **in_arr);
void	get_frac_argu_bonus(char ***in_arr_p);

#endif
