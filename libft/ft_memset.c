/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:31:10 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/08 11:35:23 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	size_t			i;
	unsigned char	*h;

	i = 0;
	h = (unsigned char *) buf;
	while (i < n)
	{
		h[i] = (unsigned char)ch;
		i ++;
	}
	return (buf);
}
