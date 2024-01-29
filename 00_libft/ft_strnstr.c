/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:41:18 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/12 14:43:47 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include"libft.h"
#include<stdio.h>

char	*srch_big(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (big[i] == little[0])
		{
			if (little[1] == '\0')
				return (((char *)big) + i);
			j = 1;
			while (big[i + j] == little[j] && (i + j) < len)
			{
				if (little[j + 1] == '\0')
					return (((char *)big) + i);
				j++;
			}
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (little[0] == '\0')
		return ((char *)big);
	if ((int)len < 0)
		len = ft_strlen(big);
	return (srch_big(big, little, len));
}
