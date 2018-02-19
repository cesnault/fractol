/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:27:01 by cesnault          #+#    #+#             */
/*   Updated: 2018/02/19 16:33:34 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "main.h"
#include <unistd.h>
#include <stdlib.h>

void		error(char *av)
{
	ft_putstr("something is wrong with this argument: ");
	ft_putstr(av);
	ft_putstr("\nTry: mandelbrot, julia, carpet, tricorne, burnedship\n");
}

void		limit(int ac, char **av, int i)
{
			if (ft_strcmp("mandelbrot", av[i]) == 0)
				ft_init_mandelbrot();
			else if (ft_strcmp("julia", av[i]) == 0)
				ft_init_julia();
			else if (ft_strcmp("carpet", av[i]) == 0)
				ft_init_carpet();
			else if (ft_strcmp("tricorne", av[i]) == 0)
				ft_init_tricorne();
			else if (ft_strcmp("burnedship", av[i]) == 0)
				ft_init_burnedship();
			else
				error(av[i]);
}

int			main(int ac, char **av)
{
	int	i;
(void) ac;
	if (ac < 2)
	{
		ft_putstr("use one or two of those words: ");
		ft_putstr("julia, mandelbrot, tricorne, burnedship, carpet\n");
		return (0);
	}
	if (ac != 2)
	{
		ft_putstr("too many argument expected 1 have ");
		ft_putnbr(ac - 1);
		ft_putstr("\nTry: mandelbrot, julia, carpet, tricorne, burnedship\n");
		return (0);
	}
	i = 1;
	limit(ac, av, i);
	return (0);
}
