/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:35:05 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/23 13:35:08 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	def_str(t_all *uk)
{
	uk->size = D_WIDTH * D_HEIGHT;
	uk->zoom_step = 1.1;
	uk->move_step = 0.09;
	if ((uk->mlx = mlx_init()) == NULL)
		exit(0);
	if (!(uk->win = mlx_new_window(uk->mlx, DD_WIDTH, D_HEIGHT, "Fractol")))
		exit(0);
	if (!(uk->image = mlx_new_image(uk->mlx, D_WIDTH, D_HEIGHT)))
		exit(0);
	if (!(uk->start_img = mlx_get_data_addr(uk->image, &uk->bits_per_pixel,
										&uk->size_line, &uk->endian)))
		exit(0);
}

void	ft_exit(void)
{
	ft_printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "[USAGE] Bad arguments",
		"-> ./fractol julia", "-> ./fractol mandelbrot",
		"-> ./fractol burningship", "-> ./fractol batman",
		"-> ./fractol mandelbrot_5", "-> ./fractol mandelbar_cubic",
		"-> ./fractol mandelbar_4", "-> ./fractal celtic");
	exit(0);
}

void	tred_exit(uint8_t l)
{
	if (l == 1)
	{
		ft_printf("ERROR; from pthread_create()");
		exit(-1);
	}
	else if (l == 2)
	{
		ft_printf("ERROR; from pthread_join()");
		exit(-1);
	}
}

void	ft_fill_points(t_all *uk)
{
	uk->a[0] = &ft_julia;
	uk->c[0] = &color_julia;
	uk->a[1] = &ft_mandelbrod;
	uk->c[1] = &color_mandelbrod;
	uk->a[2] = &fireboat;
	uk->c[2] = &color_burn;
	uk->a[3] = &batman;
	uk->c[3] = &color_batman;
	uk->a[4] = &md_5;
	uk->c[4] = &color_md_5;
	uk->a[5] = &cubic_mandelbar;
	uk->c[5] = &color_cubic_mand;
	uk->a[6] = &md_4;
	uk->c[6] = &color_md_4;
	uk->a[7] = &celtic;
	uk->c[7] = &color_celtic;
}

void	ft_check_name(char *av, t_all *uk)
{
	ft_fill_points(uk);
	if (ft_strequ(av, "julia") && def_julia(uk))
		return ;
	else if (ft_strequ(av, "mandelbrot") && def_mandelbrot(uk))
		return ;
	else if (ft_strequ(av, "burningship") && def_burningship(uk))
		return ;
	else if (ft_strequ(av, "batman") && def_batman(uk))
		return ;
	else if (ft_strequ(av, "mandelbrot_5") && def_mandelbrot_5(uk))
		return ;
	else if (ft_strequ(av, "mandelbar_cubic") && def_mandelbrot_cubic(uk))
		return ;
	else if (ft_strequ(av, "mandelbar_4") && def_mandelbar_4(uk))
		return ;
	else if (ft_strequ(av, "celtic") && def_celtic(uk))
		return ;
	ft_exit();
}
