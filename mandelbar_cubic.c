/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar_cubic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:03:42 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/03/01 18:03:45 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

uint32_t		color_cubic_mand(int i, void *test)
{
	t_mycolor	tt;
	t_all		*uk;
	double		iter;
	double		l;

	uk = (t_all *)test;
	iter = (uk->iter);
	l = (double)i / iter;
	if (i == uk->iter)
		tt.color = 0x232232 + i;
	else
	{
		tt.chanels.r = (unsigned char)(5 * (4 - l) * (1 - l) * (1 - l) * l
						* l * 205);
		tt.chanels.g = (unsigned char)(2 * (1 - l) * (1 - l) * (1 - l) *
						l * 155);
		tt.chanels.b = (unsigned char)(2 * (1 - l) * l * (1 - l) * l * 255);
		tt.chanels.a = (unsigned char)0;
	}
	return (tt.color);
}

int				def_mandelbrot_cubic(t_all *uk)
{
	uk->move_x = 0;
	uk->index = 5;
	uk->iter = 30;
	uk->zoom = 0.9;
	uk->move_y = 0;
	return (1);
}

int				cubic_mandelbar(int x, int y, void *uka)
{
	int			i;
	t_digits	d;
	t_all		*uk;

	i = -1;
	uk = (t_all*)uka;
	ft_bzero(&d, sizeof(t_digits));
	d.a = 2.0 * (x - D_WIDTH / 2) / (0.5 * uk->zoom * D_WIDTH) + uk->move_x;
	d.b = 2.0 * (y - D_HEIGHT / 2) / (0.5 * uk->zoom * D_HEIGHT) + uk->move_y;
	while ((d.rsqr + d.isqr <= 4) && (++i < uk->iter))
	{
		d.newim = ((d.rsqr * 3.0) - d.isqr) * d.newim + d.b;
		d.newre = -(d.rsqr - (d.isqr * 3)) * d.newre + d.a;
		d.isqr = d.newim * d.newim;
		d.rsqr = d.newre * d.newre;
	}
	return (i);
}
