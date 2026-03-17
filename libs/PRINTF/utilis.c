/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmati <asmati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:14:43 by asmati            #+#    #+#             */
/*   Updated: 2025/05/22 05:43:01 by asmati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	unsigned int	i;
	long			nb;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		i += ft_printchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		i += ft_printnbr(nb / 10);
	i += ft_printchar(nb % 10 + '0');
	return (i);
}

int	ft_putnbrpi(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i += ft_printchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		i += ft_putnbrpi(nb / 10);
	}
	i += ft_printchar(nb % 10 + '0');
	return (i);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	char	buf[16];
	int		i;
	int		count;

	i = 15;
	count = 0;
	if (!base)
		return (0);
	if (nbr == 0)
		return (write(1, "0x0", 3));
	while (nbr > 0)
	{
		buf[i] = base[nbr % 16];
		nbr = nbr / 16;
		i--;
	}
	count += write(1, "0x", 2);
	i++;
	while (i < 16)
		count += ft_printchar(buf[i++]);
	return (count);
}

int	ft_base16(void *ft_print_pointer)
{
	if (ft_print_pointer == NULL)
		return (write(1, "(nil)", 5));
	return (ft_putnbr_base((unsigned long)ft_print_pointer,
			"0123456789abcdef"));
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	copy = malloc(sizeof(char) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
