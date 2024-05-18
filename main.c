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

// compile line: gcc *.c -I./minilibx-linux -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm