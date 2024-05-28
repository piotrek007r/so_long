/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:46:15 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/27 08:51:02 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_escape(char **str, int *count)
{
	write (1, "%", 1);
	(*str) += 2;
	(*count)++;
}

static void	ft_nextchar(char **str, int *count)
{
	write (1, *str, 1);
	(*str)++;
	(*count)++;
}

static void	ft_invalid(char **str, int *count)
{
	(*str) += 2;
	(*count)++;
}

static void	conversions(char *str, va_list *args, int *count)
{
	while (*str)
	{
		if (*str == '%' && *(str + 1) == 'c')
			ft_putcharx(va_arg(*args, int), &str, count);
		else if (*str == '%' && (*(str + 1) == 'd' || *(str + 1) == 'i'))
			ft_putnumx(va_arg(*args, int), &str, count);
		else if (*str == '%' && *(str + 1) == 'u')
			ft_putunsintx(va_arg(*args, int), &str, count);
		else if (*str == '%' && *(str + 1) == 's')
			ft_putstrx(va_arg(*args, char *), &str, count);
		else if (*str == '%' && *(str + 1) == 'p')
			ft_putptr(va_arg(*args, size_t), &str, count);
		else if (*str == '%' && *(str + 1) == 'x')
			ft_hexlowx(va_arg(*args, unsigned int), &str, count);
		else if (*str == '%' && *(str + 1) == 'X')
			ft_hexupx(va_arg(*args, unsigned int), &str, count);
		else if (*str == '%' && *(str + 1) == '%')
			ft_escape(&str, count);
		else if (*str == '%')
			ft_invalid(&str, count);
		else
			ft_nextchar(&str, count);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			count;

	va_start (args, str);
	count = 0;
	conversions ((char *)str, &args, &count);
	va_end (args);
	return (count);
}

//   int main ()
//  {
//  	ft_printf(" %d ", 1);
//  	ft_printf(" %ds% ", 945);

//      printf("-----------------------\n");
//      ft_printf("Test for pointer: %p\n", (void *)0);
//      printf("Test for pointer: %p\n", (void *)0);
//      printf("-----------------------\n");
//      ft_printf("Test for hexadecimals: %x\n", 1834548765);
//      printf("Test for hexadecimals: %x\n", 1834548765);
//      printf("-----------------------\n");
//      ft_printf("Test for hexadecimals: %X\n", 1834548765);
//      printf("Test for hexadecimals: %X\n", 1834548765);
//      printf("-----------------------\n");
//      ft_printf("Test for unsigned int: %u\n", -100);
//      printf("Test for unsigned int: %u\n", -100);
//      printf("-----------------------\n");
//      ft_printf("Test for percent: %%d continue\n");
//      printf("Test for percent: %%d continue\n");
//      printf("-----------------------\n");
//      ft_printf("Test for other: %b countinue\n");
//      // printf("Test for other: %b\n");
//  }
