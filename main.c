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
	int i, j, k;                              // ループカウンタ
	double x, y;                              // 定数C
	int size, pixel;                          // 描く領域の一辺の長さとピクセル数
	double a, b;                              // くり返し計算に使う複素数z
	double _a, _b;                            // くり返し計算に使う複素数z（更新用）
	t_data img;                               // 描く領域の一辺の長さ
	img.line_length = 4;
	img.bits_per_pixel = 100;                             // 描く領域の一辺のピクセル数
	for (i = 0; pixel > i; i++) {            // x（実部）方向のループ
    	x = i * size / pixel - size / 2;     // 定数Cの実部
    	for (j = 0; pixel > j; j++) {        // y（虚部）方向のループ
			y = j * size / pixel - size / 2; // 定数Cの虚部
			a = 0;                           // くり返し計算に使う複素数zの実部
			b = 0;                           // くり返し計算に使う複素数zの虚部
			for (k = 0; 50 > k; k++) {       // 上限を50回とするくり返し計算
				_a = a * a - b * b + x;      // z^2+Cの計算（実部）
				_b = 2 * a * b + y;          // z^2+Cの計算（虚部）
				a = _a;                      // zの値を更新（実部）
				b = _b;                      // zの値を更新（虚部）
				if (a * a + b * b > 4) {     // もし絶対値が2を（絶対値の2乗が4を）超えていたら
					my_mlx_pixel_put(img, i, j,2);              // (i,j)の位置のピクセルを「マンデルブロ集合でない色」で塗りつぶして
					break;                   // 次の点の計算へ
				}
        }
    }
}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error: wrong number of arguments\n");
		return (0);
	}
	if (ft_strncmp(argv[1], "Mandelbrot",10) == 0)
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