/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:14 by rozeki            #+#    #+#             */
/*   Updated: 2023/09/18 15:44:41 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_data *img)
{
	if (button == 4)
	{
		img->zoom += 1.1;
	}
	else if (button == 5)
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

int	key_handler(int key, t_data *img)
{
	if (key == KB_ESC)
		exiterror("\b", img, img->mlx, img->win);
	return (0);
}
