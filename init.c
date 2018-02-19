/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:57:26 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/24 11:32:04 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "minilibx_macos/mlx.h"
#include "main.h"
#include "math.h"
#include "libft/includes/libft.h"
#include "X.h"

void		ft_init_mandelbrot(void)
{
	t_fractol mandel;

	mandel.x1 = -2.1;
	mandel.x2 = 0.6;
	mandel.y1 = -1.2;
	mandel.y2 = 1.2;
	mandel.zoom = SIZEX / (mandel.x2 - mandel.x1);
	mandel.byte = 4;
	mandel.lock = 0;
	mandel.line = 4 * SIZEX;
	mandel.endian = 0;
	mandel.burned = 0;
	mandel.precision = 50;
	mandel.mlx = mlx_init();
	mandel.win = mlx_new_window(mandel.mlx, SIZEX, SIZEX, "Mandelbrot");
	mandel.tricorne = 2;
	ft_mandelbrot_algo(&mandel);
	mlx_key_hook(mandel.win, &key, &mandel);
	mlx_mouse_hook(mandel.win, &mouse, &mandel);
	mlx_expose_hook(mandel.win, &expose_mandel, &mandel);
	mlx_loop(mandel.mlx);
}

void		ft_init_burnedship(void)
{
	t_fractol mandel;

	mandel.x1 = -2.1;
	mandel.x2 = 0.6;
	mandel.y1 = -1.2;
	mandel.y2 = 1.2;
	mandel.zoom = SIZEX / (mandel.x2 - mandel.x1);
	mandel.byte = 4;
	mandel.lock = 0;
	mandel.line = 4 * SIZEX;
	mandel.endian = 0;
	mandel.precision = 50;
	mandel.mlx = mlx_init();
	mandel.win = mlx_new_window(mandel.mlx, SIZEX, SIZEX, "Mandelbrot");
	mandel.burned = 1;
	mandel.tricorne = 2;
	burnedship(&mandel, 0, 0);
	mlx_key_hook(mandel.win, &key, &mandel);
	mlx_mouse_hook(mandel.win, &mouse, &mandel);
	mlx_expose_hook(mandel.win, &expose_mandel, &mandel);
	mlx_loop(mandel.mlx);
}

void		ft_init_julia(void)
{
	t_fractol jul;

	jul.x1 = -1.5;
	jul.x2 = 1.5;
	jul.y1 = -1.5;
	jul.y2 = 1.5;
	jul.c_r = 0;
	jul.c_i = 0;
	jul.zoom = SIZEX / (jul.x2 - jul.x1);
	jul.precision = 100;
	jul.byte = 4;
	jul.line = 4 * SIZEX;
	jul.endian = 0;
	jul.h = 2;
	jul.lock = 0;
	jul.mlx = mlx_init();
	jul.win = mlx_new_window(jul.mlx, SIZEX, SIZEX, "Julia");
	ft_julia(&jul, 0, 0);
	mlx_key_hook(jul.win, &keys, &jul);
	mlx_hook(jul.win, MotionNotify, PointerMotionMask, &julia_c, &jul);
	mlx_mouse_hook(jul.win, &mouses, &jul);
	mlx_expose_hook(jul.win, &julia_expose, &jul);
	mlx_loop(jul.mlx);
}

void		ft_init_tricorne(void)
{
	t_fractol mandel;

	mandel.x1 = -2.1;
	mandel.x2 = 0.6;
	mandel.y1 = -1.2;
	mandel.y2 = 1.2;
	mandel.zoom = SIZEX / (mandel.x2 - mandel.x1);
	mandel.byte = 4;
	mandel.lock = 0;
	mandel.line = 4 * SIZEX;
	mandel.endian = 0;
	mandel.precision = 50;
	mandel.mlx = mlx_init();
	mandel.win = mlx_new_window(mandel.mlx, SIZEX, SIZEX, "Tricorne");
	mandel.burned = 0;
	mandel.tricorne = -2;
	ft_mandelbrot_algo(&mandel);
	mlx_key_hook(mandel.win, &key, &mandel);
	mlx_mouse_hook(mandel.win, &mouse, &mandel);
	mlx_expose_hook(mandel.win, &expose_mandel, &mandel);
	mlx_loop(mandel.mlx);
}

void		ft_init_carpet(void)
{
	t_fractol carp;

	carp.x1 = 0;
	carp.x2 = 50;
	carp.y1 = 0;
	carp.y2 = 50;
	carp.zoom2 = (double)SIZEX / (carp.x2 - carp.x1);
	carp.byte = 4;
	carp.lock = 0;
	carp.line = 4 * SIZEX;
	carp.endian = 0;
	carp.mlx = mlx_init();
	carp.win = mlx_new_window(carp.mlx, SIZEX, SIZEX, "Carpet");
	carpet(&carp);
	mlx_key_hook(carp.win, &carpet_key, &carp);
	mlx_mouse_hook(carp.win, &carpet_mouse, &carp);
	mlx_expose_hook(carp.win, &expose_carpet, &carp);
	mlx_loop(carp.mlx);
}
