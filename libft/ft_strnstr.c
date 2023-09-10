/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 14:57:12 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/14 13:10:12 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	k;

	n = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[n] != '\0' && n < len)
	{
		if (haystack[n] == needle[0])
		{
			k = 0;
			while (haystack[n + k] == needle[k] && needle[k]
				&& haystack[n + k] && n + k < len)
				k ++;
			if (needle[k] == '\0')
				return ((char *)haystack + n);
		}
		n ++;
	}
	return (0);
}
