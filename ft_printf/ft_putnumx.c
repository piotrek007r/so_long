/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:46:54 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/07 22:13:28 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

static void	ft_putnum(int nb, int *count)
{
	if (nb == -2147483648)
	{
		ft_putchar('-', count);
		ft_putchar('2', count);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnum(nb / 10, count);
		ft_putchar(nb % 10 + '0', count);
	}
	else
		ft_putchar(nb % 10 + '0', count);
}

void	ft_putnumx(int nb, char **str, int *count)
{
	ft_putnum(nb, count);
	(*str) += 2;
}
