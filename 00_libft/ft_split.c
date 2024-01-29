/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 14:59:29 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/27 14:59:31 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	**ft_free(char **str, int j)
{
	while (j >= 0)
	{
		free (str[j]);
		j--;
	}
	free (str);
	return (NULL);
}

size_t	ft_elnum(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!s[0])
		return (count);
	while (s[i + 1] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c) || (i == 0 && s[i + 1] != c))
			count ++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	j;
	size_t	len_sub;

	str = malloc (sizeof(char *) * (ft_elnum(s, c) + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len_sub = 0;
			while (*s && *s != c && ++len_sub)
				s++;
			str[j] = ft_substr(s - len_sub, 0, len_sub);
			if (!(str[j]))
				return (ft_free (str, (int)j));
			j++;
		}
	}
	str[j] = 0;
	return (str);
}
