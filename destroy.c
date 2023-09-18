/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:59 by rozeki            #+#    #+#             */
/*   Updated: 2023/09/18 15:45:30 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*exiterror(char *reason, t_data *img, void *mlx, void *win)
{
	if (img->img)
	{
		ft_putendl_fd (reason, 0);
		mlx_destroy_image (mlx, img->img);
		mlx_destroy_window (mlx, win);
		exit (0);
	}
	return (NULL);
}

int	mlxfree(t_data *img)
{
	mlx_destroy_image (img->mlx, img->img);
	mlx_destroy_window (img->mlx, img->win);
	exit (0);
}
