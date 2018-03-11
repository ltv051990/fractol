/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:10:10 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/21 19:10:12 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
***** string with keyhook
*/

void			set_text(t_all *uk)
{
	mlx_string_put(uk->mlx, uk->win, 20, 20, 0x0000FF, "UDLR   - MOVE");
	mlx_string_put(uk->mlx, uk->win, 20, 40, 0xFFFF00, "- +    - ITER");
	mlx_string_put(uk->mlx, uk->win, 20, 60, 0x0000FF, "SPC - Free julia");
	mlx_string_put(uk->mlx, uk->win, 20, 80, 0xFFFF00, "+-(NL) - ZOOM");
	mlx_string_put(uk->mlx, uk->win, 20, 100, 0x0000FF, "MOUSE - julia");
}

/*
***** redraw picture
*/

void			redraw(t_all *uk)
{
	mlx_destroy_image(uk->mlx, uk->image);
	mlx_clear_window(uk->mlx, uk->win);
	if (!(uk->image = mlx_new_image(uk->mlx, D_WIDTH, D_HEIGHT)))
		exit(0);
	if (!(uk->start_img = mlx_get_data_addr(uk->image, &uk->bits_per_pixel,
										&uk->size_line, &uk->endian)))
		exit(0);
	image_draw(uk);
	mlx_put_image_to_window(uk->mlx, uk->win, uk->image, 200, 0);
	set_text(uk);
}

/*
***** one calucate functions for other treds
*/

void			*trade_picture(void *uka)
{
	t_tred		*uk;
	t_tred_d	d;

	ft_bzero(&d, sizeof(t_tred_d));
	uk = (t_tred*)uka;
	d.y = uk->start;
	d.stop = d.y + N_SIZE;
	while (d.y < d.stop)
	{
		d.x = 0;
		while (d.x < D_WIDTH)
		{
			d.i = uk->uk->a[uk->uk->index](d.x, d.y, uk->uk);
			d.col = uk->uk->c[uk->uk->index](d.i, uk->uk);
			*(unsigned int *)(uk->uk->start_img + ((d.x + d.y * D_WIDTH)
							* 4)) = d.col;
			d.x++;
		}
		d.y++;
	}
	pthread_exit(0);
}

/*
**** draw main trade to four add trades
*/

void			image_draw(t_all *uk)
{
	pthread_t	thread[NUM_THREADS];
	t_tred		a[NUM_THREADS];
	int			rc;
	long		t;

	t = -1;
	while (++t < NUM_THREADS)
	{
		a[t].start = t * N_SIZE;
		a[t].uk = uk;
		rc = pthread_create(&thread[t], NULL, trade_picture, (void *)&a[t]);
		if (rc)
			tred_exit(1);
	}
	t = -1;
	while (++t < NUM_THREADS)
	{
		rc = pthread_join(thread[t], NULL);
		if (rc)
			tred_exit(2);
	}
}

int				main(int argc, char **argv)
{
	t_all		*uk;

	uk = ft_memalloc(sizeof(t_all));
	if (argc != 2)
		ft_exit();
	ft_check_name(argv[1], uk);
	def_str(uk);
	image_draw(uk);
	mlx_put_image_to_window(uk->mlx, uk->win, uk->image, 200, 0);
	set_text(uk);
	mlx_hook(uk->win, 2, 5, ft_keys, uk);
	mlx_hook(uk->win, 4, (1L << 2), ft_mouse, uk);
	mlx_hook(uk->win, 6, (1L << 6), fractol_mouse_move_hook, uk);
	mlx_loop(uk->mlx);
	return (0);
}
