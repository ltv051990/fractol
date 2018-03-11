/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlutsyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 20:40:15 by tlutsyk           #+#    #+#             */
/*   Updated: 2018/02/21 20:40:16 by tlutsyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H
# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <float.h>
# define DD_WIDTH 1000
# define D_WIDTH 800
# define D_HEIGHT 800
# define NUM_THREADS 4
# define N_SIZE (D_HEIGHT / NUM_THREADS)

typedef int			(*t_fun_point)(int, int, void*);
typedef uint32_t	(*t_fun_color)(int, void*);

typedef	struct		s_all
{
	void			*mlx;
	void			*win;
	void			*image;
	int				widht;
	int				height;
	char			*start_img;
	int				iter;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				index;
	double			cre;
	double			cim;
	double			zoom;
	double			move_x;
	double			move_y;
	double			max_re;
	double			min_re;
	double			min_im;
	double			max_im;
	double			zoom_step;
	double			move_step;
	t_fun_point		a[8];
	t_fun_color		c[8];
	int8_t			julia_change;
	int8_t			freez;
	uint32_t		size;
}					t_all;

typedef struct		s_mmm
{
	unsigned int	b : 8;
	unsigned int	g : 8;
	unsigned int	r : 8;
	unsigned int	a : 8;
}					t_mmm;

typedef union		u_mycolor
{
	uint32_t		color;
	t_mmm			chanels;
}					t_mycolor;

typedef	struct		s_tred
{
	int				start;
	int				end;
	t_all			*uk;
}					t_tred;

typedef struct		s_tred_d
{
	int				x;
	int				y;
	int				stop;
	int				i;
	uint32_t		col;
}					t_tred_d;

typedef struct		s_digits
{
	double			a;
	double			b;
	double			rsqr;
	double			isqr;
	double			isqrsqr;
	double			rsqrsqr;
	double			irsqrsqr;
	double			newre;
	double			newim;
	double			oldim;
	double			oldre;
}					t_digits;

void				def_str(t_all *uk);
void				redraw(t_all *uk);
void				tred_exit(uint8_t l);
void				ft_exit(void);
void				ft_check_name(char *av, t_all *uk);
void				image_draw(t_all *uk);
void				ft_fill_points(t_all *uk);
int					ft_keys(int key, t_all *uk);
int					ft_julia(int x, int y, void *uk);
int					fractol_mouse_move_hook(int x, int y, t_all *uk);
int					ft_mandelbrod(int x, int y, void *uk);
int					fireboat(int x, int y, void *uka);
int					batman(int x, int y, void *uka);
int					md_5(int x, int y, void *uka);
int					cubic_mandelbar(int x, int y, void *uka);
int					md_4(int x, int y, void *uka);
int					celtic(int x, int y, void *uka);
uint32_t			color_mandelbrod(int i, void *test);
uint32_t			color_julia(int i, void *test);
uint32_t			color_burn(int i, void *test);
uint32_t			color_batman(int i, void *test);
uint32_t			color_md_5(int i, void *test);
uint32_t			color_cubic_mand(int i, void *test);
uint32_t			color_md_4(int i, void *test);
uint32_t			color_celtic(int i, void *test);
int					def_julia(t_all *uk);
int					def_celtic(t_all *uk);
int					def_batman(t_all *uk);
int					def_burningship(t_all *uk);
int					def_mandelbar_4(t_all *uk);
int					def_mandelbrot_5(t_all *uk);
int					def_mandelbrot_cubic(t_all *uk);
int					def_mandelbrot(t_all *uk);
int					ft_mouse(int mouse, int x, int y, t_all *uk);
int					fractol_mouse_move_hook(int x, int y, t_all *uk);

#endif
