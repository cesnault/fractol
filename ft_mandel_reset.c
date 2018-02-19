/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:03:11 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/29 13:59:42 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_mandel_reset(t_fractol *mandel)
{
	mandel->x1 = -2.1;
	mandel->x2 = 0.6;
	mandel->y1 = -1.2;
	mandel->y2 = 1.2;
	mandel->zoom = SIZEX / (mandel->x2 - mandel->x1);
	ft_mandelbrot_algo(mandel);
}
