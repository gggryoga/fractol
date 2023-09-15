#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double constant_x;
	double constant_y;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	calculate(double a, double b,t_data img, int i, int j)
{
	double new_a;
	double new_b;
	int k;

	k = 0;
	while (k < K_MAX)
	{
		new_a = a * a - b * b + img.constant_x;  // 複素数zの実部を更新
		new_b = 2.0 * a * b + img.constant_y;  // 複素数zの虚部を更新
		if (new_a * new_a + new_b * new_b > 4.0)
			break;
		a = new_a;
		b = new_b;
		k++;
	}
	if (k == K_MAX)
		my_mlx_pixel_put(&img, i, j, 0xff00ff);  // (i,j)の位置のピクセルを「マンデルブロ集合でない色」で塗りつぶして
	else if (k < K_MAX && k > K_MAX * 0.04)
		my_mlx_pixel_put(&img, i, j, 0x00990000);  // (i,j)の位置のピクセルを「マンデルブロ集合である色」で塗りつぶして
	else
		my_mlx_pixel_put(&img, i, j, 0x000000);  // (i,j)の位置のピクセルを「マンデルブロ集合である色」で塗りつぶして
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

int	julia(t_data img, char *real, char *imaginary)
{
	int		i;
	int		j;
	double	a;
	double	b;

	i = 0;
	img.constant_x = my_atof (real, 0, 0, 0, 0);
	img.constant_y = my_atof (imaginary, 0, 0, 0, 0);
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			a = (i - WIDTH / 2.0) / (WIDTH / 4.0);
			b = (j - HEIGHT / 2.0) / (HEIGHT / 4.0);
			j = calculate(a, b, img, i, j);
		}
		i++;
	}
	return (0);
}

int	mandelbrot(t_data img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			img.constant_x = (i - WIDTH / 2.0) / (WIDTH / 4.0);
			img.constant_y = (j - HEIGHT / 2.0) / (HEIGHT / 4.0);
			j = calculate(0, 0, img, i, j);
		}
		i++;
	}
	return (0);
}

void	create_img_and_select(char *str, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, str);
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr (img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	if (ft_strncmp(str, "Mandelbrot", 11) == 0)
		mandelbrot(img);
	else if (ft_strncmp (str, "Julia", 6) == 0)
		julia (img, argv[2], argv[3]);
	else
	{
		printf ("Error: wrong argument\n");
		exit (1);
	}
	mlx_put_image_to_window (mlx, mlx_win, img.img, 0, 0);
	mlx_loop (mlx);
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
