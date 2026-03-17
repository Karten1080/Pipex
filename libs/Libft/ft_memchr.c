/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:36:33 by asmati            #+#    #+#             */
/*   Updated: 2025/05/05 19:05:51 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		cc;
	const unsigned char	*ss;
	size_t				i;

	i = 0;
	cc = c;
	ss = (const unsigned char *)s;
	while (i < n)
	{
		if (ss[i] == cc)
		{
			return ((void *) &ss[i]);
		}
		i++;
	}
	return (NULL);
}
