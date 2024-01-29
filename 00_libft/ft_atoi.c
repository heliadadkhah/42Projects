/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:55:42 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/12 15:26:01 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

int	ft_isspace(char c)
{
	if (c == 32)
		return (1);
	if (c >= 9 && c <= 13)
		return (1);
	return (0);
}

int	ft_int( char *nptr, char sign, int i)
{
	int	res;

	res = 0;
	while (ft_isdigit(((char *)nptr)[i]))
	{
		res *= 10;
		res += ((char *)nptr)[i] - '0';
		if (res == 214748364)
			if (((char *)nptr)[i + 1] == '8' && sign == '-')
				return (-2147483648);
		i++;
	}
	if (sign == '-')
		res *= -1;
	return (res);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		res;
	char	sign;

	sign = '+';
	res = 0;
	i = 0;
	while (((char *)nptr)[i] != '\0')
	{
		while (ft_isspace(((char *)nptr)[i]))
			i++;
		if (((char *)nptr)[i] == '+' || ((char *)nptr)[i] == '-')
		{
			sign = ((char *)nptr)[i];
			i++;
		}
		if (!(ft_isdigit(((char *)nptr)[i])))
			return (0);
		else
		{
			res = ft_int((char *)nptr, sign, i);
			return (res);
		}
	}
	return (0);
}
