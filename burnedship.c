/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnedship.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:58:51 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/29 13:11:52 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "main.h"
#include "math.h"
#include <stdlib.h>
#include "X.h"

int		burnedship_iteration(t_fractol *fract, double z_r, double z_i)
{
	double	tmp;
	int		i;

	i = 0;
	while ((z_r * z_r + z_i * z_i) < 4 && i < fract->precision)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + fract->c_r;
		if (z_r < 0)
			z_r *= -1;
		z_i = fract->tricorne * z_i * tmp + fract->c_i;
		if (z_i < 0)
			z_i *= -1;
		i++;
	}
	return (i);
}

void	burnedship(t_fractol *fract, double z_r, double z_i)
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
			fract->c_r = (double)x / fract->zoom + fract->x1;
			fract->c_i = (double)y / fract->zoom + fract->y1;
			i = burnedship_iteration(fract, z_r, z_i);
			ft_color_pixel(fract, i, index);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	mlx_destroy_image(fract->mlx, fract->image);
}
