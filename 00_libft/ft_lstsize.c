/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdadkhah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:21:37 by hdadkhah          #+#    #+#             */
/*   Updated: 2022/12/26 12:21:40 by hdadkhah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*ptr;

	if (!lst)
		return (0);
	size = 0;
	ptr = lst;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
		size++;
	}
	return (size + 1);
}
