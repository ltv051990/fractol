/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:54:01 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/03/01 17:54:12 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				fireboat(int x, int y, void *uka)
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
		d.newim = fabsl(d.newre * d.newim) * 2 + d.b;
		d.newre = d.oldre * d.oldre - d.oldim * d.oldim + d.a;
	}
	return (i);
}

uint32_t		color_burn(int i, void *test)
{
	t_mycolor	tt;
	t_all		*uk;
	double		iter;
	double		d;

	uk = (t_all *)test;
	iter = (uk->iter);
	d = (double)i / iter;
	if (i == uk->iter)
		tt.color = 0x0;
	else
	{
		tt.chanels.b = (unsigned char)(5 * (1 - d) * (1 - d) * (1 - d) * d * d
						* 255);
		tt.chanels.g = (unsigned char)(4 * i);
		tt.chanels.r = (unsigned char)(7 * (1 - d) * d * d * 255);
		tt.chanels.a = (unsigned char)(50);
	}
	return (tt.color);
}

int				def_burningship(t_all *uk)
{
	uk->index = 2;
	uk->move_x = -0.3;
	uk->iter = 30;
	uk->zoom = 0.9;
	uk->move_y = -0.3;
	return (1);
}
