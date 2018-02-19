/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_algo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:46:38 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/24 15:26:43 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "main.h"
#include "math.h"
#include "X.h"
#include <stdlib.h>

int		key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69 && ((t_fractol *)param)->precision <= 300)
		((t_fractol *)param)->precision += 50;
	if (keycode == 78 && ((t_fractol *)param)->precision >= 100)
		((t_fractol *)param)->precision -= 50;
	if (keycode == 15)
		ft_mandel_reset((t_fractol *)param);
	ft_key_movement((t_fractol *)param, keycode);
	if (((t_fractol *)param)->burned == 0)
	{
		ft_mandelbrot_algo((t_fractol *)param);
	}
	else
		burnedship((t_fractol *)param, 0, 0);
	return (0);
}

int		mouse(int button, int x, int y, void *param)
{
	if (button == 1)
		ft_movement((t_fractol *)param, x, y);
	if (button == 2)
		ft_zoom((t_fractol *)param, 0);
	if (button == 4)
	{
		ft_movement((t_fractol *)param, x, y);
		ft_zoom((t_fractol *)param, 0);
	}
	if (button == 5 && (((t_fractol *)param)->zoom / 1.05 > 20))
	{
		ft_movement((t_fractol *)param, x, y);
		ft_zoom((t_fractol *)param, 1);
	}
	if (((t_fractol *)param)->burned == 0)
	{
		ft_mandelbrot_algo((t_fractol *)param);
	}
	else
		burnedship((t_fractol *)param, 0, 0);
	return (0);
}

int		ft_mandelbrot_iteration(t_fractol *fract)
{
	double	tmp;
	int		i;

	F->z_i = 0;
	F->z_r = 0;
	i = 0;
	while ((F->z_r * F->z_r + F->z_i * F->z_i) < 4 && i < F->precision)
	{
		tmp = F->z_r;
		F->z_r = F->z_r * F->z_r - F->z_i * F->z_i + F->c_r;
		F->z_i = F->tricorne * F->z_i * tmp + F->c_i;
		i++;
	}
	return (i);
}

void	rendering(void *arg)
{
	int i;
	int index;

	(TF)->y = 0;
	while ((TF)->y < SIZEX)
	{
		index = (((TF)->x) * 4) + (((TF)->y) * (TF)->line) - 4;
		ft_reset_color((TF), index);
		(TF)->c_r = (double)(TF)->x / (TF)->zoom + (TF)->x1;
		(TF)->c_i = (double)(TF)->y / (TF)->zoom + (TF)->y1;
		i = ft_mandelbrot_iteration((TF));
		ft_color_pixel((TF), i, index);
		(TF)->y += 1;
	}
}

void	ft_mandelbrot_algo(t_fractol *fract)
{
	fract->x = 0;
	fract->image = mlx_new_image(fract->mlx, SIZEX, SIZEX);
	fract->data = mlx_get_data_addr(F->image, &F->byte, &F->line, &F->endian);
	while (fract->x < SIZEX)
	{
		fract->y = 0;
		rendering(fract);
		fract->x += 1;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	mlx_destroy_image(fract->mlx, fract->image);
}
