# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scorbion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 13:13:07 by scorbion          #+#    #+#              #
#    Updated: 2018/02/19 16:33:59 by cesnault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
LIB = libfdf.a
OBJS = main.o \
	   burnedship.o \
	   carpet.o \
	   expose_carpet.o \
	   expose_mandel.o \
	   ft_carpet_reset.o \
	   ft_color.o \
	   ft_color_pixel.o \
	   ft_julia_reset.o \
	   ft_key_movement.o \
	   ft_mandel_reset.o \
	   ft_mandelbrot_algo.o \
	   ft_movement.o \
	   ft_movement_carpet.o \
	   ft_reset_color.o \
	   ft_zoom.o \
	   init.o \
	   julia.o \
	   keys.o \



INCLUDES =  -I minilibx_macos/ -I libft/includes/ minilibx_macos/libmlx.a libft/libft.a
FLAGS =  
FRM = -framework openGL -framework Appkit
.PHONY:all clean
all : $(NAME)

$(NAME) : $(OBJS) 
	make -C libft
	make -C minilibx_macos
	ar rc $(LIB) $(OBJS)
	gcc $(FLAGS) $(INCLUDES) $(LIB) -o $(NAME) $(FRM)
%.o: %.c
	gcc $(FLAGS) -c $^

clean :
	rm -f $(OBJS)
	make clean -C libft
	make clean -C minilibx_macos

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)
	make fclean -C libft

re : fclean all

