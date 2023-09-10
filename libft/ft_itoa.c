/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:39:07 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/11 13:00:00 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len ++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*h;
	long	num;
	int		len;

	len = ft_len(n);
	num = n;
	h = malloc(sizeof(char) * len + 1);
	if (h == NULL)
		return (NULL);
	if (num < 0)
	{
		h[0] = '-';
		num = -num;
	}
	h[len] = '\0';
	len --;
	if (num == 0)
		h[len] = '0';
	while (num)
	{
		h[len] = num % 10 + '0';
		len --;
		num = num / 10;
	}
	return (h);
}
