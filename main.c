#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int mandelbrot(void)
{
	void	*mlx;
	void	*mlx_win;
	int i, j, k;                              // ループカウンタ
	double x, y;                              // 定数C
	double a, b;                              // くり返し計算に使う複素数z
	double _a, _b;                            // くり返し計算に使う複素数z（更新用）
	t_data img;                               // 描く領域の一辺の長さ
	img.line_length = 1920;
	img.bits_per_pixel = 1080;                             // 描く領域の一辺のピクセル数
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, img.line_length, img.bits_per_pixel, "Hello world!");
	img.img = mlx_new_image(mlx, img.line_length, img.bits_per_pixel);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
								i = 0;
	while (i < img.line_length)
	{
		j = 0;
		while (j < img.bits_per_pixel)
		{
			x = (i - img.line_length / 2) / (img.line_length / 4);            // ピクセルの位置を定数Cの実部に変換
			y = (j - img.bits_per_pixel / 2) / (img.line_length / 4);            // ピクセルの位置を定数Cの虚部に変換
			a = 0.0;                          // zの実部を0に初期化
			b = 0.0;                          // zの虚部を0に初期化
			k = 0;                            // くり返し回数を0に初期化
			while (a * a + b * b < 4.0 && k < 256)
			{
				_a = a * a - b * b + x;        // zの実部を更新
				_b = 2.0 * a * b + y;          // zの虚部を更新
				a = _a;                        // zの実部を更新
				b = _b;                        // zの虚部を更新
				k++;                           // くり返し回数を1増やす
			}
			my_mlx_pixel_put(&img, i, j, k * 256 * 256); // (i,j)の位置のピクセルを「マンデルブロ集合でない色」で塗りつぶして
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);              // (i,j)の位置のピクセルを「マンデルブロ集合でない色」で塗りつぶして
	return 0;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error: wrong number of arguments\n");
		return (0);
	}
	if (ft_strncmp(argv[1], "Mandelbrot",11) == 0)
	{
		mandelbrot();
	}
	// else if (ft_strncmp(argv[1], "Julia" 6) == 0)
	// {

	// }
	// else 
	// {
	// 	printf("Error: wrong argument\n");
	// 	return (0);
	// }


}