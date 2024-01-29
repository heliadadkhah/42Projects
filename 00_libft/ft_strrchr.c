/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:35:01 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/12 15:35:03 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include"libft.h"
#include<stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	c %= 128;
	s_len = ft_strlen(s);
	i = s_len;
	while (i > 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
	if (s[0] == c)
		return ((char *)s + i);
	return (NULL);
}
/*
in strchr and strrchr
The terminating null byte is  considered  part  of the string.
*/
