
#include "so_long.h"

int    close_win()
{
    exit(0);
    return (0);
}

int main()
{
    void    *win;
    void    *mlx;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 800, 600, "test");
    mlx_hook(win, 17, 0, close_win, NULL);
    mlx_loop(mlx);

}