/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_carpet_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:45:59 by cesnault          #+#    #+#             */
/*   Updated: 2017/03/16 15:46:02 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_carpet_reset(t_fractol *carp)
{
	carp->x1 = -1.5;
	carp->x2 = 1.5;
	carp->y1 = -1.5;
	carp->y2 = 1.5;
	carp->zoom = SIZEX / (carp->x2 - carp->x1);
	carpet(carp);
}
