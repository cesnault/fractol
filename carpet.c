/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carpet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:22:13 by cesnault          #+#    #+#             */
/*   Updated: 2018/02/19 16:23:29 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "main.h"
#include "math.h"
#include <stdlib.h>

int		carpet_key(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 15)
		ft_carpet_reset((t_fractol *)param);
	ft_key_movement((t_fractol *)param, keycode);
	carpet((t_fractol *)param);
	return (0);
}

int		carpet_mouse(int button, int x, int y, void *param)
{
	double dist;

	if (button == 1 || button == 4)
	{
		ft_movement_carpet((t_fractol *)param, x, y);
		dist = fabs(((SIZEX / 2)) / PZOOM2 - (SIZEX / 2) / (PZOOM2 * 1.05));
		((t_fractol*)param)->zoom2 *= 1.05;
		((t_fractol *)param)->x1 += dist;
		((t_fractol *)param)->x2 -= dist;
		((t_fractol *)param)->y1 += dist;
		((t_fractol *)param)->y2 -= dist;
	}
	if (button == 2 || button == 5)
	{
		ft_movement_carpet((t_fractol *)param, x, y);
		dist = fabs(((SIZEX / 2)) / PZOOM2 - (SIZEX / 2) / (PZOOM2 / 1.05));
		((t_fractol*)param)->zoom2 /= 1.05;
		((t_fractol *)param)->x1 += dist;
		((t_fractol *)param)->x2 -= dist;
		((t_fractol *)param)->y1 += dist;
		((t_fractol *)param)->y2 -= dist;
	}
	carpet(((t_fractol *)param));
	return (0);
}

int		carpet_algo(int x, int y)
{
	int i;

	i = x;
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (0);
		x /= 3;
		y /= 3;
	}
	return (1);
}

void	carpet_color(t_fractol *carpet, int index, double x2, double y2)
{
	if (carpet_algo((int)x2, (int)y2) == 1)
	{
		carpet->data[index + 2] = (char)255;
	}
}

void	carpet(t_fractol *carpet)
{
	int		x;
	int		y;
	int		index;
	double	x2;
	double	y2;

	x = 0;
	carpet->image = mlx_new_image(carpet->mlx, SIZEX, SIZEX);
	C->data = mlx_get_data_addr(C->image, &C->byte, &C->line, &C->endian);
	while (x < SIZEX)
	{
		y = 0;
		while (y < SIZEX)
		{
			x2 = (double)x / carpet->zoom2 + carpet->x1;
			y2 = (double)y / carpet->zoom2 + carpet->y2;
			index = x * 4 + y * carpet->line - 4;
			carpet_color(carpet, index, x2, y2);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(carpet->mlx, carpet->win, carpet->image, 0, 0);
	mlx_destroy_image(carpet->mlx, carpet->image);
}
