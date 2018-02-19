/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesnault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:47:37 by cesnault          #+#    #+#             */
/*   Updated: 2017/04/24 12:20:36 by cesnault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define PRECISION 100
# define SIZEX 1000.0
# define SIZEY 500
# define ZOOM (double)fract->zoom
# define C carpet
# define PZOOM  (double)(((t_fractol *)param)->zoom)
# define PZOOM2 (double)(((t_fractol *)param)->zoom2)
# define F fract
# define TF (t_fractol *)arg
# include "math.h"

typedef struct	s_fractol
{
	void			*mlx;
	void			*win;
	void			*image;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	int				h;
	int				tricorne;
	int				burned;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	int				x;
	int				y;
	unsigned long	zoom;
	double			zoom2;
	int				precision;
	char			*data;
	int				byte;
	int				endian;
	int				lock;
	int				color;
	int				line;
	int				endline;
}				t_fractol;

void			ft_init_mandelbrot(void);
void			ft_init_burnedship(void);
void			ft_init_julia(void);
void			ft_init_tricorne(void);
void			ft_init_carpet(void);
void			limit(int ac, char **av, int i);
int				expose_carpet(void *param);
void			ft_julia(t_fractol *fract, double z_r, double z_i);
void			ft_init_julia();
void			ft_mandelbrot_algo(t_fractol *fract);
void			burnedship(t_fractol *fract, double z_r, double z_i);
void			ft_mandel_reset(t_fractol *mandel);
void			ft_julia_reset(t_fractol *jul);
void			carpet(t_fractol *carpet);
void			ft_carpet_reset(t_fractol *carpet);
int				julia_expose(void *param);
int				expose_mandel(void *param);
int				expose_carpet(void *param);
int				carpet_mouse(int button, int x, int y, void *param);
int				julia_c(int x, int y, void *param);
int				key(int keycodem, void *param);
int				keys(int keycode, void *param);
int				carpet_key(int keycode, void *param);
int				mouse(int button, int x, int y, void *param);
int				mouses(int button, int x, int y, void *param);
void			ft_color(t_fractol *fract, int index, int i);
void			ft_zoom(t_fractol *fract, int x);
void			ft_movement(t_fractol *fract, int x, int y);
void			ft_movement_carpet(t_fractol *fract, int x, int y);
void			ft_key_movement(t_fractol *fract, int keycode);
void			ft_reset_color(t_fractol *fract, int index);
void			ft_color_pixel(t_fractol *fract, int i, int index);
int				keys(int keycode, void *param);
#endif
