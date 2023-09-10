/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:36:30 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/11 18:41:02 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if (count > SIZE_MAX / size)
		return (NULL);
	dest = malloc(count * size);
	if (dest == NULL)
		return (NULL);
	ft_memset((unsigned char *)dest, 0, count * size);
	return (dest);
}
// int main(void)
// {
// 	char *j;
// 	j = ft_calloc(3,4);
// 	printf("%s",j);
// }
