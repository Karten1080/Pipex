/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:01:33 by asmati            #+#    #+#             */
/*   Updated: 2025/05/03 16:02:20 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	s2;

	s2 = ft_strlen(needle);
	if (s2 == 0)
	{
		return ((char *)haystack);
	}
	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (haystack[i + j] && needle[j] && (i + j) < len && haystack[i
				+ j] == needle[j])
		{
			j++;
			if (j == s2)
			{
				return ((char *)(haystack + i));
			}
		}
		i++;
	}
	return (NULL);
}
