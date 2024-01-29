/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:12:10 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/12 17:12:14 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substr;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		len = 0;
		s_len = 0;
	}
	i = 0;
	if ((int)len < 0 || len > s_len)
		len = s_len;
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc (len + 1);
	if (!substr)
		return (NULL);
	while (i < s_len && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
