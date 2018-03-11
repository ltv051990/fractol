/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   celtic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:53:18 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/03/01 17:53:24 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				celtic(int x, int y, void *uka)
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
		d.newre = fabs(d.newre * (d.rsqrsqr - 10 * d.irsqrsqr + 5 * d.isqrsqr))
						+ d.a;
		d.isqrsqr = d.newim * d.newim * d.newim * d.newim;
		d.rsqrsqr = d.newre * d.newre * d.newre * d.newre;
		d.irsqrsqr = (d.newre * d.newre) * (d.newim * d.newim);
	}
	return (i);
}

int				def_celtic(t_all *uk)
{
	uk->move_x = 0;
	uk->index = 7;
	uk->iter = 30;
	uk->zoom = 0.8;
	uk->move_y = 0;
	return (1);
}

uint32_t		color_celtic(int i, void *test)
{
	t_mycolor	tt;
	t_all		*uk;
	double		t;

	uk = (t_all *)test;
	t = (double)i / uk->iter;
	if (i == uk->iter)
		tt.color = 0x0F0500;
	else
	{
		tt.chanels.b = (unsigned char)(3 * i);
		tt.chanels.g = (unsigned char)((t * 500 - i));
		tt.chanels.r = (unsigned char)(t * 600 - i);
		tt.chanels.a = (unsigned char)(50);
	}
	return (tt.color);
}
