/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:36:52 by rozeki            #+#    #+#             */
/*   Updated: 2022/11/13 17:38:07 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (s != NULL && f != NULL)
	{
		i = ft_strlen(s);
		while (n < i)
		{
			(*f)(n, s);
			s++;
			n++;
		}
	}
}
