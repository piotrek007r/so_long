/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:11:45 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/19 14:14:19 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main() {
    void *mlx;
    void *window;
    void *img;

    mlx = mlx_init();
    window = mlx_new_window(mlx, 800, 600, "Hello World");
    mlx_loop(mlx);

    img = mlx_new_image(mlx, 800, 600);

    return 0;
}
