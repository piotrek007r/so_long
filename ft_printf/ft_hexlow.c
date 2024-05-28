/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:47:45 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/07 22:05:48 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

static void	ft_hexlow(unsigned int nb, char *hex_numbers, int *count)
{
	if (nb >= 16)
	{
		ft_hexlow(nb / 16, hex_numbers, count);
		ft_putchar(hex_numbers[nb % 16], count);
	}
	else
		ft_putchar(hex_numbers[nb % 16], count);
}

void	ft_hexlowx(unsigned int nb, char **str, int *count)
{
	char	*hex_numbers;

	hex_numbers = "0123456789abcdef";
	ft_hexlow(nb, hex_numbers, count);
	(*str) += 2;
}
