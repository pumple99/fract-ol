/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghoy <seunghoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:37:30 by seunghoy          #+#    #+#             */
/*   Updated: 2023/02/22 14:37:32 by seunghoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/pf_printf.h"

int	print_possible_input_bonus(void)
{
	ft_printf("Possible Input List\n");
	ft_printf("Fractal type: Mandelbrot = 0, Julia = 1, bonus = 2\n");
	ft_printf("Mandelbrot: need no argument\n");
	ft_printf("Julia, bonus: need 2 argument [real value] [imaginary value]\n");
	ft_printf("You must enter a value one million times larger \n");
	ft_printf("than the actual value as an integer\n");
	ft_printf("Ex) 1 123456 88888 -> draw julia with 0.123456 0.088888\n");
	return (0);
}
