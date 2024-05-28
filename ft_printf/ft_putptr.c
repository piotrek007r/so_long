/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:47:01 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/08 11:51:43 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

static void	ft_hexlow(size_t nb, char *hex_numbers, int *count)
{
	if (nb >= 16)
	{
		ft_hexlow(nb / 16, hex_numbers, count);
		ft_putchar(hex_numbers[nb % 16], count);
	}
	else
		ft_putchar(hex_numbers[nb % 16], count);
}

void	ft_putptr(size_t adress, char **str, int *count)
{
	char	*hex_numbers;

	hex_numbers = "0123456789abcdef";
	if (adress == 0)
		ft_putstrx("(nil)", str, count);
	else
	{
		write(1, "0x", 2);
		(*count) += 2;
		ft_hexlow(adress, hex_numbers, count);
		(*str) += 2;
	}
}
