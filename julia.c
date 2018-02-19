/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:55:54 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/24 14:53:14 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "main.h"
#include "math.h"
#include <stdlib.h>
#include "X.h"

int		mouses(int button, int x, int y, void *param)
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
	ft_julia((t_fractol *)param, 0, 0);
	return (0);
}

int		ft_julia_algo(t_fractol *fract, double z_r, double z_i)
{
	double	tmp;
	int		i;

	i = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && i < fract->precision)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + fract->c_r;
		z_i = 2 * z_i * tmp + fract->c_i;
		i++;
	}
	return (i);
}

void	ft_julia(t_fractol *fract, double z_r, double z_i)
{
	int x;
	int y;
	int i;
	int index;

	x = 0;
	fract->image = mlx_new_image(fract->mlx, SIZEX, SIZEX);
	fract->data = mlx_get_data_addr(F->image, &F->byte, &F->line, &F->endian);
	while (x < SIZEX)
	{
		y = 0;
		while (y < SIZEX)
		{
			index = ((x) * 4) + ((y) * fract->line) - 4;
			ft_reset_color(fract, index);
			z_r = (double)x / fract->zoom + fract->x1;
			z_i = (double)y / fract->zoom + fract->y1;
			i = ft_julia_algo(fract, z_r, z_i);
			ft_color_pixel(fract, i, index);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	mlx_destroy_image(fract->mlx, fract->image);
}
