/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:46:57 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 15:47:00 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "minilibx_macos/mlx.h"

void	ft_reset_color(t_fractol *fract, int index)
{
	fract->data[index] = 0;
	fract->data[index + 1] = 0;
	fract->data[index + 2] = 0;
}
