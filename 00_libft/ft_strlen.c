/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:25:13 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/12 13:29:19 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		counter ++;
		i ++;
	}
	return (counter);
}
