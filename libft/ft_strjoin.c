/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:11:36 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/14 13:09:33 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*h;
	size_t		n;
	size_t		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	h = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (h == NULL)
		return (NULL);
	n = 0;
	j = 0;
	while (s1[n])
	{
		h[n] = s1[n];
		n ++;
	}
	while (s2[j])
	{
		h[n] = s2[j];
		n ++;
		j ++;
	}
	h[n] = '\0';
	return (h);
}
