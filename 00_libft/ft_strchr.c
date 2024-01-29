/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:37:52 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/12 14:39:53 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include"libft.h"
#include<stdio.h>

char	*ft_strchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	c %= 128;
	i = 0;
	s_len = ft_strlen(s);
	while (i <= s_len)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
