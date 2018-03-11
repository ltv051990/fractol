/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:53:00 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/03/01 17:53:07 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				def_mandelbrot_5(t_all *uk)
{
	uk->move_x = 0;
	uk->index = 4;
	uk->iter = 30;
	uk->zoom = 0.9;
	uk->move_y = 0;
	return (1);
}

uint32_t		color_md_5(int i, void *test)
{
	t_mycolor	tt;
	t_all		*uk;
	double		iter;
	double		t;

	uk = (t_all *)test;
	iter = (uk->iter);
	t = (double)i / iter;
	if (i == uk->iter)
		tt.color = 0x0;
	else
	{
		tt.chanels.b = (unsigned char)(300 * i * t);
		tt.chanels.g = (unsigned char)(20 * (1 - t) * (1 - t) * (1 - t) * t
						* t * 255);
		tt.chanels.r = (unsigned char)(10 * (1 - t) * t * t * 255);
		tt.chanels.a = (unsigned char)(70);
	}
	return (tt.color);
}

int				md_5(int x, int y, void *uka)
{
	int			i;
	t_all		*uk;
	t_digits	d;

	i = -1;
	uk = (t_all*)uka;
	ft_bzero(&d, sizeof(t_digits));
	d.a = 2.0 * (x - D_WIDTH / 2) / (0.5 * uk->zoom * D_WIDTH) + uk->move_x;
	d.b = 2.0 * (y - D_HEIGHT / 2) / (0.5 * uk->zoom * D_HEIGHT) + uk->move_y;
	while ((d.newim * d.newim + d.newre * d.newre) <= 4 && ++i < uk->iter)
	{
		d.newim = d.newim * (5 * d.rsqrsqr - 10 * d.irsqrsqr + d.isqrsqr) + d.b;
		d.newre = d.newre * (d.rsqrsqr - 10 * d.irsqrsqr + 5 * d.isqrsqr) + d.a;
		d.isqrsqr = d.newim * d.newim * d.newim * d.newim;
		d.rsqrsqr = d.newre * d.newre * d.newre * d.newre;
		d.irsqrsqr = (d.newre * d.newre) * (d.newim * d.newim);
	}
	return (i);
}
