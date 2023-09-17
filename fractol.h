#ifndef FRACTOL_H
# define FRACTOL_H


# define WIDTH 800
# define HEIGHT 800
# define K_MAX 50
#  define KB_ESC 53
# define ZOOM_FACTOR 2
# define ON_DESTROY 12

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double constant_x;
	double constant_y;
	void	*mlx;
	void	*win;
	char	*win_name;
	double	zoom;
	char	*real;
	char	*imaginary;
}				t_data;

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
// # include "minilibx-linux/mlx.h"
#include <mlx.h>
#endif

