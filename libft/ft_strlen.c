/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:46:24 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/27 10:12:53 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

//int main()
//{
//	printf("Total lenght of string: %zu\n", ft_strlen("This"));
//	printf("Total lenght of string: %zu\n", ft_strlen(""));
//	printf("Total lenght of string: %zu\n", ft_strlen(" "));
//}
