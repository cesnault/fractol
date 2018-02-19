/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:48:44 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/29 12:31:43 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "math.h"

void	ft_zoom(t_fractol *fract, int x)
{
	double dist;

	if (x == 0 && (fabs((SIZEX / 2) / ZOOM - (SIZEX / 2) / ZOOM * 1.05))
			< 4294967295)
	{
		dist = fabs((SIZEX / 2) / ZOOM - (SIZEX / 2) / ZOOM * 1.05);
		fract->zoom *= 1.05;
	}
	else
	{
		dist = fabs((SIZEX / 2) / ZOOM - (SIZEX / 2) / ZOOM / 1.05);
		fract->zoom /= 1.05;
	}
	fract->x1 += dist;
	fract->x2 -= dist;
	fract->y1 += dist;
	fract->y2 -= dist;
}
