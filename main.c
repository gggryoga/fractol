/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:56:44 by rozeki            #+#    #+#             */
/*   Updated: 2023/09/18 15:15:36 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	calculate(double a, double b, t_data *img)
{
	double	new_a;
	double	new_b;
	int		k;

	k = 0;
	while (k < K_MAX)
	{
		new_a = a * a - b * b + img->constant_x;
		new_b = 2.0 * a * b + img->constant_y;
		if (new_a * new_a + new_b * new_b > 4.0)
			break ;
		a = new_a;
		b = new_b;
		k++;
	}
	if (k == K_MAX)
		my_mlx_pixel_put (img, img->i, img->j, 0x000000);
	else if (k < K_MAX && k > K_MAX * 0.7)
		my_mlx_pixel_put (img, img->i, img->j, 0xffffff);
	else if (k <= K_MAX * 0.7  && k > K_MAX * 0.02)
		my_mlx_pixel_put (img, img->i, img->j, 0x0000FF);
	else
		my_mlx_pixel_put (img, img->i, img->j, 0xffffff);
	return (img->j + 1);
}

void	putimg(t_data *img, char **argv)
{
	if (ft_strncmp(img->win_name, "Mandelbrot", 11) == 0)
		mandelbrot(img);
	else if (ft_strncmp (img->win_name, "Julia", 6) == 0)
		julia (img, argv[2], argv[3]);
	else
	{
		printf ("Error: wrong argument\nexp: ./fractol Mandelbrot\n");
		printf ("exp: ./fractol Julia -0.4 0.6\n");
		exit (1);
	}
	mlx_put_image_to_window (img->mlx, img->win, img->img, 0, 0);
}

void	create_img_and_select(char *str, char **argv)
{
	t_data	img;

	img.zoom = 1.0;
	img.win_name = str;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, img.win_name);
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr (img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	putimg(&img, argv);
	mlx_hook(img.win, 2, 5, key_handler, &img);
	mlx_hook(img.win, 17, 0L, mlxfree, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_loop (img.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && ft_strncmp (argv[1], "Mandelbrot", 11) == 0)
		create_img_and_select(argv[1], argv);
	else if (argc == 4 && ft_strncmp (argv[1], "Julia", 6) == 0)
		create_img_and_select(argv[1], argv);
	else
	{
		printf("Error: wrong argument\n");
		exit(1);
	}
	return (0);
}

// __attribute__((destructor))
// static void	destructor(void){
// 	system("leaks -q fractol");
// }