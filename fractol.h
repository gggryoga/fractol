/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:38:54 by rozeki            #+#    #+#             */
/*   Updated: 2023/09/18 15:41:01 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
// # include "minilibx-linux/mlx.h"
# include <mlx.h>

# define WIDTH 800
# define HEIGHT 800
# define K_MAX 50
# define KB_ESC 53
# define ZOOM_FACTOR 2
# define ON_DESTROY 12

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	constant_x;
	double	constant_y;
	void	*mlx;
	void	*win;
	char	*win_name;
	double	zoom;
	char	*real;
	char	*imaginary;
	int		i;
	int		j;
}				t_data;

int		mandelbrot(t_data *img);
int		julia(t_data *img, char *str_one, char *str_two);
int		calculate(double a, double b, t_data *img);
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		mouse_hook(int button, int x, int y, t_data *img);
int		key_handler(int key, t_data *img);
void	create_img_and_select(char *str, char **argv);
void	putimg(t_data *img, char **argv);
void	*exiterror(char *reason, t_data *img, void *mlx, void *win);
int		mlxfree(t_data *img);

#endif
