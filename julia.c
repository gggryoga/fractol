/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:43:04 by rozeki            #+#    #+#             */
/*   Updated: 2023/09/18 15:43:56 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	my_atof(char *str, int i, int j, double num)
{
	int		sign;
	double	dec;

	sign = 1;
	dec = 0.0;
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
	double	a;
	double	b;

	img->i = 0;
	img->real = str_one;
	img->imaginary = str_two;
	img->constant_x = my_atof (img->real, 0, 0, 0);
	img->constant_y = my_atof (img->imaginary, 0, 0, 0);
	while (img->i < WIDTH)
	{
		img->j = 0;
		while (img->j < HEIGHT)
		{
			a = (img->i - WIDTH / 2.0) / (WIDTH * img->zoom / 4.0);
			b = (img->j - HEIGHT / 2.0) / (HEIGHT * img->zoom / 4.0);
			img->j = calculate(a, b, img);
		}
		img->i++;
	}
	return (0);
}
