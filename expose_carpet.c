/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_carpet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:15:29 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/29 11:17:27 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "main.h"

int		expose_carpet(void *param)
{
	carpet((t_fractol *)param);
	return (0);
}
