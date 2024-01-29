/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:46:13 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/12 13:49:07 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	ret_val;
	size_t	i;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size > dst_len)
		ret_val = dst_len + src_len;
	else
		ret_val = src_len + size;
	while (((char *)src)[i] != '\0' && (dst_len + i + 1) < size)
	{
		((char *)dst)[dst_len + i] = ((char *)src)[i];
		i++;
	}
	((char *)dst)[dst_len + i] = '\0';
	return (ret_val);
}
