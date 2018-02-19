/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:26:41 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/24 12:09:53 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "main.h"

void	ft_color_next(t_fractol *fract, int index, int i)
{
	fract->data[index + 2] = 255 * ((double)i / (double)fract->precision);
	fract->data[index + 1] = 128 * ((double)i / (double)fract->precision);
}

void	ft_color(t_fractol *fract, int index, int i)
{
	if ((double)i / (double)fract->precision < 0.143)
		fract->data[index + 2] = 255 * ((double)i / (double)fract->precision);
	else if ((double)i / (double)fract->precision < 0.286)
		ft_color_next(fract, index, i);
	else if ((double)i / (double)fract->precision < 0.429)
	{
		fract->data[index + 2] = 255 * ((double)i / (double)fract->precision);
		fract->data[index + 1] = 255 * ((double)i / (double)fract->precision);
	}
	else if ((double)i / (double)fract->precision < 0.571)
		fract->data[index + 1] = 255 * ((double)i / (double)fract->precision);
	else if ((double)i / (double)fract->precision < 0.714)
	{
		fract->data[index + 1] = 255 * ((double)i / (double)fract->precision);
		fract->data[index] = 255 * ((double)i / (double)fract->precision);
	}
	else if ((double)i / (double)fract->precision < 0.857)
		fract->data[index] = 255 * ((double)i / (double)fract->precision);
	else if ((double)i / (double)fract->precision < 1.0)
	{
		fract->data[index + 2] = 255 * ((double)i / (double)fract->precision);
		fract->data[index + 1] = 255 * ((double)i / (double)fract->precision);
	}
}
