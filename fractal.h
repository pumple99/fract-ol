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
# define KEY_ESC 53
# define KEY_LEFT 123

typedef struct	s_temp
{
	void	*mlx;
	void	*win;
}	t_temp;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     create_trgb(int t, int r, int g, int b);
int     get_mandelbrot_color(int x, int y);
void	draw_mandelbrot(void);

//print.c
int     print_possible_input(void);
int     print_try_again(void);

#endif
