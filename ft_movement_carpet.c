/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_carpet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:55:37 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 17:31:03 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "main.h"

void	ft_movement_carpet(t_fractol *fract, int x, int y)
{
	double cx;
	double cy;

	cx = fabs((SIZEX / 2) / fract->zoom2 - (double)x / fract->zoom2);
	cy = fabs((SIZEX / 2) / fract->zoom2 - (double)y / fract->zoom2);
	if (x > (SIZEX / 2))
	{
		fract->x1 += cx;
		fract->x2 += cx;
	}
	else
	{
		fract->x1 -= cx;
		fract->x2 -= cx;
	}
	if (y > (SIZEX / 2))
	{
		fract->y1 += cy;
		fract->y2 += cy;
	}
	else
	{
		fract->y1 -= cy;
		fract->y2 -= cy;
	}
}
