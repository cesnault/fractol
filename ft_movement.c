/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:48:28 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 17:28:47 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "main.h"

void	ft_movement(t_fractol *fract, int x, int y)
{
	double cx;
	double cy;

	cx = fabs((SIZEX / 2) / fract->zoom - (double)x / fract->zoom);
	cy = fabs((SIZEX / 2) / fract->zoom - (double)y / fract->zoom);
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
