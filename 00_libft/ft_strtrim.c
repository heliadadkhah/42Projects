/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:35:48 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/12 17:35:51 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

size_t	trim_head(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, (int)s1[i]))
		i ++;
	return (i);
}

size_t	trim_tail(char const *s1, char const *set, size_t start)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	if (start == ft_strlen(s1))
		return (i);
	while (s1[i] && ft_strchr(set, (int)s1[i]))
		i --;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;
	size_t	i;

	start = trim_head(s1, set);
	end = trim_tail(s1, set, start);
	i = 0;
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (NULL);
	if (ft_strlen(s1) && (int)(end - start) >= 0)
	{
		while (start + i <= end)
		{
			str[i] = s1[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
