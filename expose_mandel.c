/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_mandel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 12:01:21 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/24 12:01:51 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		expose_mandel(void *param)
{
	if (((t_fractol *)param)->burned == 0)
		ft_mandelbrot_algo((t_fractol *)param);
	else
		burnedship((t_fractol *)param, 0, 0);
	return (0);
}
