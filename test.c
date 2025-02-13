// #include "so_long.h"

// void    load_images(void *mlx, t_images *images)
// {
//     int width;
//     int hight;
//     images->wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &hight);
//     images->player = mlx_xpm_file_to_image(mlx, "player.xpm", &width, &hight);
//     images->collectible = mlx_xpm_file_to_image(mlx, "collectible.xpm", &width, &hight);
//     images->floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &width, &hight);
//     images->exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &width, &hight);
// }

// void draw_map(void *mlx, void *win, char **map, t_images images)
// {
//     int i;
//     int j;
//     int tile_size = 32;

//     i = 0;
//     while (map[i])
//     {
//         j = 0;
//         while (map[i][j])
//         {
//             if (map[i][j] == '1')
//                 mlx_put_image_to_window(mlx, win, images.wall, j * tile_size, i * tile_size);
//             else if (map[i][j] == '0')
//                 mlx_put_image_to_window(mlx, win, images.floor, j * tile_size, i * tile_size);
//             else if (map[i][j] == 'P')
//                 mlx_put_image_to_window(mlx, win, images.player, j * tile_size, i * tile_size);
//             else if (map[i][j] == 'C')
//                 mlx_put_image_to_window(mlx, win, images.collectible, j * tile_size, i * tile_size);
//             else if (map[i][j] == 'E')
//                 mlx_put_image_to_window(mlx, win, images.exit, j * tile_size, i * tile_size);
//             j++;
//         }
//         i++;
//     }
// }

// // void press_key()
// // {
    
// // }

// int main(int argc, char **argv)
// {
//     char **map;
//     int hight_map;
//     size_t  width_map;
//     void    *mlx;
//     void    *win;
//     t_images    images;
//     t_data  data;

//     hight_map = 0;
//     width_map = 0;
//     if (argc < 2)
//     {
//         write(1, "\n", 1);
//         return (0);
//     }
//     data.map = handle_input(argv[1], &hight_map, &width_map);
//     data.mlx = mlx_init();
//     if (!(data.mlx))
//     {
//         perror("Error initializing MiniLibX");
//         return (0);
//     }
//     data.win = mlx_new_window(mlx, (width_map * 32), (hight_map * 32), "so_long");
//     load_images(data.mlx, &images);
//     draw_map(data.mlx, data.win, data.map, images);
//     mlx_loop(data.mlx);
// }



































































// Function to load image from path
// void *load_image(void *mlx, char *path)
// {
//     void *img;
//     int img_width;
//     int img_height;

//     img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
//     if (!img)
//     {
//         perror("Error loading image");
//         exit(1);
//     }
//     return img;
// }

// // Function to draw map
// void draw_map(void *mlx, void *win, char **map, t_images images)
// {
//     int x, y;
//     int tile_size = 32;  // Size of each tile in pixels

//     y = 0;
//     while (map[y])
//     {
//         x = 0;
//         while (map[y][x])
//         {
//             if (map[y][x] == '1')  // Wall
//                 mlx_put_image_to_window(mlx, win, images.wall, x * tile_size, y * tile_size);
//             else if (map[y][x] == 'P')  // Player
//                 mlx_put_image_to_window(mlx, win, images.player, x * tile_size, y * tile_size);
//             else if (map[y][x] == 'C')  // Collectible
//                 mlx_put_image_to_window(mlx, win, images.collectible, x * tile_size, y * tile_size);
//             else if (map[y][x] == '0')  // Floor
//                 mlx_put_image_to_window(mlx, win, images.floor, x * tile_size, y * tile_size);
//             else if (map[y][x] == 'E')  // Exit
//                 mlx_put_image_to_window(mlx, win, images.exit, x * tile_size, y * tile_size);
//             x++;
//         }
//         y++;
//     }
// }

// int main(int argc, char **argv)
// {
//     void *mlx;
//     void *win;
//     char **map;
//     int len_window = 0;
//     size_t width_window = 0;

//     // Check if the map file path is provided
//     if (argc < 2)
//     {
//         write(2, "Error\n", 6);
//         exit(1);
//     }

//     map = handle_input(argv[1], &len_window, &width_window);

//     // Initialize MiniLibX
//     mlx = mlx_init();
//     if (!mlx)
//     {
//         perror("Error initializing MiniLibX");
//         return (0);
//     }

//     // Create a window
//     win = mlx_new_window(mlx, ((width_window) * 32), ((len_window) * 32), "so long");
//     // win = mlx_new_window(mlx, 800, 420, "so long");
//     if (!win)
//     {
//         perror("Error creating window");
//         return (0);
//     }
//     // Load images
//     t_images images;
//     images.wall = load_image(mlx, "/home/klamachi/Desktop/so_long/wall.xpm");
//     images.player = load_image(mlx, "/home/klamachi/Desktop/so_long/player.xpm");
//     images.collectible = load_image(mlx, "/home/klamachi/Desktop/so_long/collectible.xpm");
//     images.exit = load_image(mlx, "/home/klamachi/Desktop/so_long/exit.xpm");
//     images.floor = load_image(mlx, "/home/klamachi/Desktop/so_long/floor.xpm");

//     // Draw the map
//     draw_map(mlx, win, map, images);

//     // Start the MiniLibX event loop
//     mlx_loop(mlx);

//     return (0);
// }


// int main(int argc, char **argv)
// {
//     void    *mlx;
//     void    *win;
//     char    **map;
//     if (argc < 2)
//     {
//         write(2, "Error\n", 6);
//         exit(1);
//     }
//     map = handle_input(argv[1]);
//     mlx = mlx_init();
//     if (!mlx)
//     {
//         perror("Error initializing MiniLibX");
//         return (0);
//     }
//     win = mlx_new_window(mlx, 800, 600, "so long");
//     if (!win)
//     {
//         perror("Error creating window");
//         return (0);
//     }
//     mlx_loop(mlx);
//     return (0);
// }