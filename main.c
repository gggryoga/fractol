#include "fractol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	calculate(double a, double b,t_data *img, int i, int j)
{
	double new_a;
	double new_b;
	int k;

	k = 0;
	while (k < K_MAX)
	{
		new_a = a * a - b * b + img->constant_x;  // 複素数zの実部を更新
		new_b = 2.0 * a * b + img->constant_y;  // 複素数zの虚部を更新
		if (new_a * new_a + new_b * new_b > 4.0)
			break;
		a = new_a;
		b = new_b;
		k++;
	}
	if (k == K_MAX)
		my_mlx_pixel_put(img, i, j, 0xff00ff);  // (i,j)の位置のピクセルを「マンデルブロ集合でない色」で塗りつぶして
	else if (k < K_MAX && k > K_MAX * img->zoom * 0.04)
		my_mlx_pixel_put(img, i, j, 0x00990000);  // (i,j)の位置のピクセルを「マンデルブロ集合である色」で塗りつぶして
	else
		my_mlx_pixel_put(img, i, j, 0x000000);  // (i,j)の位置のピクセルを「マンデルブロ集合である色」で塗りつぶして
	return (j + 1);
}

double my_atof(char *str, int i, int j, double num, double dec)
{
	int sign;

	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '.' && str[i] != '\0')
		num = num * 10 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (str[i] != '\0')
		{
			dec = dec * 10 + (str[i++] - '0');
			j++;
		}
	}
	while (j-- > 0)
		dec = dec / 10;
	return (sign * (num + dec));
}

int	julia(t_data *img, char *str_one, char *str_two)
{
	int		i;
	int		j;
	double	a;
	double	b;

	i = 0;
	img->real = str_one;
	img->imaginary = str_two;
	img->constant_x = my_atof (img->real, 0, 0, 0, 0);
	img->constant_y = my_atof (img->imaginary, 0, 0, 0, 0);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			a = (i - WIDTH / 2.0) / (WIDTH * img->zoom / 4.0);
			b = (j - HEIGHT / 2.0) / (HEIGHT * img->zoom / 4.0);
			j = calculate(a, b, img, i, j);
		}
		i++;
	}
	return (0);
}

int	mandelbrot(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			img->constant_x = (i - WIDTH / 2.0) / (WIDTH *img->zoom / 4.0);
			img->constant_y = (j - HEIGHT / 2.0) / (HEIGHT * img->zoom/ 4.0);
			if (i == 0 && j == 0)
			{
				printf("img->constant_x: %f\n", img->constant_x);
				printf("img->constant_y: %f\n", img->constant_y);
			}
			j = calculate(0, 0, img, i, j);
		}
		i++;
	}
	return (0);
}

void		*exiterror(char *reason, t_data *img, void *mlx, void *win)
{
	if (img->img)
	{
		ft_putendl_fd(reason,0);
		mlx_destroy_image(mlx, img->img);
		mlx_destroy_window(mlx, win);
		exit(0);
	}
	return (NULL);
}

void putimg(t_data *img, char **argv)
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

int mouse_hook(int button, int x, int y, t_data *img)
{
	if (button == 4) // マウスホイールを上にスクロールした場合（拡大）
	{
		img->zoom += 1.1;
	}
	else if (button == 5) // マウスホイールを下にスクロールした場合（縮小）
	{
		img->zoom *= 0.9;
	}
	else
		return (0);
	(void)x;
	(void)y;
	if (ft_strncmp(img->win_name, "Mandelbrot", 11) == 0)
		mandelbrot(img);
	else if (ft_strncmp(img->win_name, "Julia", 6) == 0)
		julia(img, img->real, img->imaginary);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int			key_handler(int key, t_data *img)
{
	if (key == KB_ESC)
		exiterror("\b", img, img->mlx, img->win);
	return (0);
}

int mlxfree(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	exit(0);
}

void	create_img_and_select(char *str, char **argv)
{
	t_data	img;

	img.zoom = 1;
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


__attribute__((destructor))
static void	destructor(void){
	system("leaks -q fractol");
}