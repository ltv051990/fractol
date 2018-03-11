/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:52:30 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/03/01 17:52:34 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				ft_julia(int x, int y, void *uka)
{
	int			i;
	t_all		*uk;
	t_digits	d;

	uk = (t_all*)uka;
	ft_bzero(&d, sizeof(t_digits));
	i = -1;
	d.newre = 1.75 * (x - D_WIDTH / 2) / (0.5 * uk->zoom * D_WIDTH)
			+ uk->move_x;
	d.newim = 1.75 * (y - D_HEIGHT / 2) / (0.5 * uk->zoom * D_HEIGHT)
			+ uk->move_y;
	while ((d.newre * d.newre + d.newim * d.newim) <= 4 && ++i < uk->iter)
	{
		d.a = d.newre;
		d.b = d.newim;
		d.newre = d.a * d.a - d.b * d.b + uk->cre;
		d.newim = 2 * d.a * d.b + uk->cim;
	}
	return (i);
}

int				def_julia(t_all *uk)
{
	uk->zoom = 0.9;
	uk->move_y = 0;
	uk->cre = -0.7;
	uk->cim = 0.27015;
	uk->iter = 50;
	uk->julia_change = 1;
	uk->move_x = 0;
	uk->index = 0;
	uk->max_re = 1.0;
	uk->min_re = -2.0;
	uk->min_im = -1.2;
	uk->max_im = uk->min_im + (uk->max_re - uk->min_re) - D_HEIGHT / D_WIDTH;
	return (1);
}

uint32_t		color_julia(int i, void *test)
{
	t_mycolor	tt;
	t_all		*uk;
	double		iter;
	double		t;

	iter = (uk->iter);
	uk = (t_all *)test;
	t = (double)i / iter;
	if (i == uk->iter)
		tt.color = 0x0;
	else
	{
		tt.chanels.r = (10 * (1 - t) * t * t * 255);
		tt.chanels.g = (5 * (1 - t) * (1 - t) * (1 - t) * t * t * 255);
		tt.chanels.b = (unsigned char)10;
		tt.chanels.a = 0;
	}
	return (tt.color);
}
