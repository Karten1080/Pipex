/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:06:35 by asmati            #+#    #+#             */
/*   Updated: 2025/05/03 19:10:10 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*dtr;

	i = 0;
	if (src == 0 && dst == 0)
		return (dst);
	dtr = (unsigned char *)dst;
	str = (unsigned char *)src;
	while (i < n)
	{
		dtr[i] = str[i];
		i++;
	}
	return (dst);
}
