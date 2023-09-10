/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:07:42 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/14 13:05:38 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(long int n, const char c)
{
	long int	jdg1;
	long int	jdg2;

	jdg1 = LONG_MAX / 10;
	jdg2 = LONG_MAX % 10;
	if (n > jdg1)
		return (0);
	if (n == jdg1 && c - 48 > jdg2)
		return (0);
	return (1);
}

static int	underflow(long int n, const char c)
{
	long int	jdg1;
	long int	jdg2;

	jdg1 = LONG_MIN / 10;
	jdg2 = LONG_MIN % 10;
	if (n < jdg1)
		return (0);
	if (n == jdg1 / 10 && (c - 48) * (-1) < jdg2)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long int		ans;
	int				c;
	unsigned int	i;

	ans = 0;
	i = 0;
	c = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			c *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (c == 1 && overflow(ans, str[i]) == 0)
			return ((int)LONG_MAX);
		if (c == -1 && underflow(-1 * ans, str[i + 1]) == 0)
			return ((int)LONG_MIN);
		ans = ans * 10 + (str[i++] - '0');
	}
	return (ans * c);
}

// #include <stdlib.h>
// #include <stdio.h>
// int main()
// {
// 	int a = ft_atoi("9223372036854775806");
// 	printf("ft_atoi : %d",a);
// 	int b = atoi("9223372036854775806");
// 	printf("\natoi : %d",b);
// }
