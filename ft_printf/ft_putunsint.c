/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:47:37 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/07 22:20:05 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

static void	ft_putunsint(unsigned int nb, int *count)
{
	if (nb >= 10)
	{
		ft_putunsint(nb / 10, count);
		ft_putchar(nb % 10 + '0', count);
	}
	else
		ft_putchar(nb % 10 + '0', count);
}

void	ft_putunsintx(unsigned int nb, char **str, int *count)
{
	ft_putunsint (nb, count);
	(*str) += 2;
}
