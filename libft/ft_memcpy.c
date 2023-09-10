/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:06:12 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/08 13:15:13 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char	*cpd;
	unsigned char	*cps;
	size_t			i;

	cpd = (unsigned char *)dst;
	cps = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	else
	{
		i = 0;
		while (i < n)
		{
			cpd[i] = cps[i];
			i ++;
		}
	}
	return (cpd);
}
