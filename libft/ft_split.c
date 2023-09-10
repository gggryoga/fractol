/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rozeki <rozeki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:01:24 by rozeki            #+#    #+#             */
/*   Updated: 2022/12/14 13:08:41 by rozeki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_lst(char **ans)
{
	while (*ans)
	{
		free (*ans);
		ans++;
	}
	free (ans);
}

static void	fill_ans(char const *s, char c, char **ans)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c)
			len ++;
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
		{
			*ans = ft_substr(s, i - len + 1, len);
			if (*ans++ == NULL)
			{
				free_lst(ans);
				return ;
			}
			len = 0;
		}
		i ++;
	}
	*ans = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ans;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			len ++;
		i++;
	}
	ans = (char **)malloc(sizeof(char *) * (len + 1));
	if (ans == NULL)
		return (NULL);
	fill_ans(s, c, ans);
	return (ans);
}
