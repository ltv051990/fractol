/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   batman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:53:40 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/03/01 17:53:44 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				batman(int x, int y, void *uka)
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
		d.oldre = d.newre;
		d.oldim = d.newim;
		d.newim = 4 * d.newre * d.newim * ((d.newre * d.newre) -
					(d.newim * d.newim)) + d.b;
		d.newre = (d.newre * d.newre) * (d.newre * d.newre) +
				((d.newim * d.newim) * (d.newim * d.newim)) -
				(6 * d.newre * d.newre * d.newim * d.newim) + d.a;
	}
	return (i);
}

int				def_batman(t_all *uk)
{
	uk->move_x = -0.5;
	uk->index = 3;
	uk->iter = 20;
	uk->zoom = 0.8;
	uk->move_y = 0;
	return (1);
}

uint32_t		color_batman(int i, void *test)
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
		tt.chanels.b = (unsigned char)(5 * (1 - t) * (1 - t) * (1 - t) *
						t * t * 255);
		tt.chanels.g = (unsigned char)(4 * i);
		tt.chanels.r = (unsigned char)(7 * (1 - t) * t * t * 255);
		tt.chanels.a = (unsigned char)(10);
	}
	return (tt.color);
}
