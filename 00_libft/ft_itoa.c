/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:47:18 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/20 16:47:21 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*int_min(void)
{
	char	*str;

	str = (char *) malloc (12);
	if (!str)
		return (NULL);
	ft_strlcpy (str, "-2147483648", 12);
	return (str);
}

size_t	digitsnum(int n)
{
	int	dn;

	dn = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		dn++;
	}
	return (dn);
}

char	*fill_str(int n, char *str, int sign, int length)
{
	int	i;

	str[length] = '\0';
	i = length - 1;
	while (i >= sign)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i --;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n < 0)
	{
		if (n == -2147483648)
			str = int_min();
		else
		{
			n *= -1;
			str = (char *) malloc (digitsnum(n) + 2);
			if (!str)
				return (NULL);
			str[0] = '-';
			str = fill_str(n, str, 1, digitsnum(n) + 1);
		}
	}
	else
	{
		str = (char *) malloc (digitsnum(n) + 1);
		if (!str)
			return (NULL);
		str = fill_str(n, str, 0, digitsnum(n));
	}
	return (str);
}
