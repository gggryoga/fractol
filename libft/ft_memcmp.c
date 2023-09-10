/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:46:55 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/11 18:39:18 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*h1;
	unsigned char	*h2;
	size_t			c;

	h1 = (unsigned char *)s1;
	h2 = (unsigned char *)s2;
	c = 0;
	while (c < n)
	{
		if (h1[c] > h2[c])
			return (h1[c] - h2[c]);
		else if (h2[c] > h1[c])
			return (h1[c] - h2[c]);
		c++;
	}
	return (0);
}
