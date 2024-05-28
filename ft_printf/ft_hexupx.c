/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:56:39 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/08 11:50:45 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *count)
{
	if (c >= 'a' && c <= 'z')
	{
		c = c - 32;
	}
	write(1, &c, 1);
	(*count)++;
}

static void	ft_hexup(unsigned int nb, char *hex_numbers, int *count)
{
	if (nb >= 16)
	{
		ft_hexup(nb / 16, hex_numbers, count);
		ft_putchar(hex_numbers[nb % 16], count);
	}
	else
		ft_putchar(hex_numbers[nb % 16], count);
}

void	ft_hexupx(unsigned int nb, char **str, int *count)
{
	char	*hex_numbers;

	hex_numbers = "0123456789abcdef";
	ft_hexup (nb, hex_numbers, count);
	(*str) += 2;
}
