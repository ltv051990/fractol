/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbar_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:54:58 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/03/01 17:55:01 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				md_4(int x, int y, void *uka)
{
	int			i;
	t_all		*uk;
	t_digits	d;

	i = -1;
	uk = (t_all*)uka;
	ft_bzero(&d, sizeof(t_digits));
	d.a = 2.0 * (x - D_WIDTH / 2) / (0.5 * uk->zoom * D_WIDTH) + uk->move_x;
	d.b = 2.0 * (y - D_HEIGHT / 2) / (0.5 * uk->zoom * D_HEIGHT) + uk->move_y;
	while ((d.newre * d.newre + d.newim * d.newim) <= 4 && ++i < uk->iter)
	{
		d.newim = -4 * d.newre * d.newim * (d.rsqr - d.isqr) + d.b;
		d.newre = d.rsqr * d.rsqr + d.isqr * d.isqr - 6 * d.rsqr * d.isqr
					+ d.a;
		d.isqr = d.newim * d.newim;
		d.rsqr = d.newre * d.newre;
	}
	return (i);
}

int				def_mandelbar_4(t_all *uk)
{
	uk->move_x = 0;
	uk->index = 6;
	uk->iter = 30;
	uk->zoom = 0.9;
	uk->move_y = 0;
	return (1);
}

uint32_t		color_md_4(int i, void *test)
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
		tt.chanels.b = (unsigned char)((2 * (1 - t) * (1 - t) * (1 - t)
						* t * 155));
		tt.chanels.g = (unsigned char)(10 * (1 - t) * t * t * 255);
		tt.chanels.r = (unsigned char)(7 * (1 - t) * t * t * 255);
		tt.chanels.a = (unsigned char)(120);
	}
	return (tt.color);
}
