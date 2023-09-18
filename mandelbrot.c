/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:55:39 by rozeki            #+#    #+#             */
/*   Updated: 2023/09/18 15:41:45 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	cordinate(int tmp)
{
	return ((tmp - WIDTH / 2.0) / (WIDTH * 4.0));
}

int	mandelbrot(t_data *img)
{
	img->i = 0;
	while (img->i < WIDTH)
	{
		img->j = 0;
		while (img->j < HEIGHT)
		{
			img->constant_x = cordinate(img->i) * img->zoom;
			img->constant_y = cordinate(img->j) * img->zoom;
			img->j = calculate(0, 0, img);
		}
		img->i++;
	}
	return (0);
}
