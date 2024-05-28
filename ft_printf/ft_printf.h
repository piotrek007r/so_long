/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:46:41 by pruszkie          #+#    #+#             */
/*   Updated: 2024/04/07 22:25:40 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putcharx(char c, char **str, int *count);
void	ft_putstrx(char *s1, char **s2, int *count);
void	ft_putnumx(int nb, char **str, int *count);
void	ft_putunsintx(unsigned int nb, char **str, int *count);
void	ft_putptr(size_t adress, char **str, int *count);
void	ft_hexlowx(unsigned int nb, char **str, int *count);
void	ft_hexupx(unsigned int nb, char **str, int *count);

#endif
