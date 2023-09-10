/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:02:51 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/08 11:25:21 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dmem;
	unsigned char	*smem;

	i = 0;
	dmem = (unsigned char *)dest;
	smem = (unsigned char *)src;
	if (dmem == NULL && smem == NULL)
		return (NULL);
	if (dmem > smem)
	{
		while (n-- > 0)
			dmem[n] = smem[n];
	}
	else
	{
		while (i < n)
		{
			dmem[i] = smem[i];
			i++;
		}
	}
	return (dmem);
}
