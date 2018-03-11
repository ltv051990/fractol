/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 17:52:48 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/03/01 17:52:50 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int				def_mandelbrot(t_all *uk)
{
	uk->move_x = -0.5;
	uk->index = 1;
	uk->iter = 30;
	uk->zoom = 0.9;
	uk->move_y = 0;
	return (1);
}

uint32_t		color_mandelbrod(int i, void *test)
{
	t_mycolor	t;
	t_all		*uk;

	uk = (t_all*)test;
	if (i == uk->iter)
		t.color = 0x0;
	else
	{
		t.chanels.b = (unsigned char)(2 * i);
		t.chanels.g = (unsigned char)(2 * i);
		t.chanels.r = (unsigned char)(7 * i);
		t.chanels.a = (unsigned char)(50);
	}
	return (t.color);
}

int				ft_mandelbrod(int x, int y, void *uka)
{
	int			i;
	t_digits	t;
	t_all		*uk;

	ft_bzero(&t, sizeof(t_digits));
	uk = (t_all*)uka;
	i = -1;
	t.a = (x - D_WIDTH / 2) / (0.5 * uk->zoom * D_WIDTH) + uk->move_x;
	t.b = (y - D_HEIGHT / 2) / (0.5 * uk->zoom * D_HEIGHT) + uk->move_y;
	while ((t.newre * t.newre + t.newim * t.newim) <= 4 && ++i < uk->iter)
	{
		t.oldre = t.newre;
		t.oldim = t.newim;
		t.newre = t.oldre * t.oldre - t.oldim * t.oldim + t.a;
		t.newim = 2 * t.oldre * t.oldim + t.b;
	}
	return (i);
}
