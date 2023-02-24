/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:34:23 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/22 14:34:25 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractal.h"

int	get_bonus_color(int x, int y, t_all *all)
{
	int		re;
	t_coord	c;

	re = -1;
	c.a = all->real;
	c.b = all->imaginary;
	c.x0 = 0;
	c.y0 = 0;
	c.x1 = (x - all->pos.mid_x) / all->pos.accum + all->pos.mid_realx;
	c.y1 = (y - all->pos.mid_y) / all->pos.accum + all->pos.mid_realy;
	while (++re < MAX_RECURSION)
	{
		if (c.x1 * c.x1 + c.y1 * c.y1 > 4)
			break ;
		c.x2 = c.x1 * c.x1 - c.y1 * c.y1 + c.a + c.b * c.x0;
		c.y2 = 2 * c.x1 * c.y1 + c.b * c.y0;
		c.x0 = c.x1;
		c.y0 = c.y1;
		c.x1 = c.x2;
		c.y1 = c.y2;
	}
	return (create_trgb(50, re * 8, re * 8, re * 8));
}
