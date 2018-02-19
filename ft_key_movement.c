/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:47:58 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/24 12:33:44 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_key_movement(t_fractol *fract, int keycode)
{
	if (keycode == 123)
	{
		fract->x1 -= 0.1;
		fract->x2 -= 0.1;
	}
	if (keycode == 124)
	{
		fract->x1 += 0.1;
		fract->x2 += 0.1;
	}
	if (keycode == 125)
	{
		fract->y1 += 0.1;
		fract->y2 += 0.1;
	}
	if (keycode == 126)
	{
		fract->y1 -= 0.1;
		fract->y2 -= 0.1;
	}
}
