/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 19:55:16 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/03/01 19:55:19 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	esc_exit(t_all *uk)
{
	mlx_destroy_image(uk->mlx, uk->image);
	mlx_destroy_window(uk->mlx, uk->win);
	exit(0);
}

void	zoom_cost(t_all *uk)
{
	uk->zoom = uk->zoom / uk->zoom_step < 0.1 ? uk->zoom : uk->zoom /
	uk->zoom_step;
	uk->move_step /= 0.9;
}

int		ft_keys(int key, t_all *uk)
{
	if (key == 53)
		esc_exit(uk);
	else if (key == 69)
	{
		uk->zoom *= uk->zoom_step;
		uk->move_step *= 0.9;
	}
	else if (key == 78)
		zoom_cost(uk);
	else if (key == 24)
		uk->iter = uk->iter + 5 > 200 ? uk->iter : uk->iter + 5;
	else if (key == 27)
		uk->iter = uk->iter - 5 < 20 ? uk->iter : uk->iter - 5;
	else if (key == 124)
		uk->move_x += uk->move_step;
	else if (key == 123)
		uk->move_x -= uk->move_step;
	else if (key == 126)
		uk->move_y -= uk->move_step;
	else if (key == 125)
		uk->move_y += uk->move_step;
	else if (key == 49)
		uk->freez = uk->freez == 0 ? 1 : 0;
	redraw(uk);
	return (0);
}

int		ft_mouse(int mouse, int x, int y, t_all *uk)
{
	if (mouse == 5)
	{
		uk->zoom *= uk->zoom_step;
		uk->move_step *= 0.9;
	}
	else if (mouse == 4)
		zoom_cost(uk);
	redraw(uk);
	return (0);
}

int		fractol_mouse_move_hook(int x, int y, t_all *uk)
{
	if (uk->julia_change != 1)
		return (0);
	if (uk->freez == 0)
	{
		x = x - D_WIDTH;
		y = y - D_HEIGHT;
		uk->cim = uk->max_im - (double)y * (uk->min_im) / D_HEIGHT;
		uk->cre = uk->min_re + (double)x * (uk->max_re * uk->min_re) / D_WIDTH;
		redraw(uk);
	}
	return (0);
}
