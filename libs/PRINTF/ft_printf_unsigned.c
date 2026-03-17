/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:21:54 by asmati            #+#    #+#             */
/*   Updated: 2025/05/22 05:36:41 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	ft_num_len(unsigned int num)
{
	unsigned int	len;

	len = 0;
	while (num > len)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = ft_uitoa(n);
	i += ft_putstrp(str);
	free(str);
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	i;
	unsigned int	tmp;
	char			*res;

	if (n == 0)
		return (ft_strdup("0"));
	tmp = n;
	i = 0;
	while (tmp != 0)
	{
		i++;
		tmp = tmp / 10;
	}
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (n != 0)
	{
		res[i - 1] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (res);
}
