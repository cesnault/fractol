/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:47:16 by cesnault          #+#    #+#             */
/*   Updated: 2017/05/24 15:22:21 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "stdlib.h"

int	julia_expose(void *param)
{
	ft_julia((t_fractol *)param, 0, 0);
	return (0);
}

int	julia_c(int x, int y, void *param)
{
	double center;

	if (((t_fractol *)param)->lock == 0)
	{
		center = (SIZEX / 2) / (double)(((t_fractol *)param)->zoom);
		((t_fractol *)param)->c_r = (double)x / PZOOM - center;
		((t_fractol *)param)->c_i = (double)y / PZOOM - center;
		ft_julia((t_fractol *)param, 0, 0);
	}
	return (0);
}

int	keys(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 37)
	{
		if (((t_fractol *)param)->lock == 0)
			((t_fractol *)param)->lock = 1;
		else
			((t_fractol *)param)->lock = 0;
	}
	ft_key_movement((t_fractol *)param, keycode);
	if (keycode == 69 && ((t_fractol *)param)->precision <= 300)
		((t_fractol *)param)->precision += 50;
	if (keycode == 78 && ((t_fractol *)param)->precision >= 100)
		((t_fractol *)param)->precision -= 50;
	if (keycode == 15)
		ft_julia_reset((t_fractol *)param);
	ft_julia((t_fractol *)param, 0, 0);
	return (0);
}
