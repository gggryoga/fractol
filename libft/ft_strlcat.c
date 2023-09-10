/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:52:57 by rozeki            #+#    #+#             */
/*   Updated: 2022/11/30 19:24:18 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;
	size_t	count;

	count = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (count);
	i = 0;
	s = 0;
	while (dst[i] && i < dstsize)
		i ++;
	while (src[s] && (i + s + 1) < dstsize)
	{
		dst[i + s] = src[s];
		s ++;
	}
	if (i < dstsize)
		dst[i + s] = '\0';
	return (i + count);
}
