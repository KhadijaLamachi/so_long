// hi i am no moving to work on the so long project so the first thing that i did is to handle the input the input of the program is the path of the map that i work on it i check if its path correct and if it is rectangulare comtain one player and at leact one C and just one E and so one like u see in my code : int main(int argc, char **argv)
// {
//     void    *mlx;
//     void    *win;
//     t_data  img;
//     if (argc < 2)
//     {
//         write(2, "Error\n", 6);
//         exit(1);
//     }
//     handle_input(argv[1]);
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
//     img.img = mlx_new_image(mlx, 800, 600);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    
//     mlx_put_image_to_window(mlx, win, img.img, 0, 0);
//     mlx_loop(mlx);
//     return (0);
// }                                     static void free_line(char *line, const char *msg)
// {
//     free(line);
//     perror(msg);
//     exit(1);
// }

// int    is_rectangular(int fd)
// {
//     char    *line;
//     size_t     len;
//     int nb_lines;

//     nb_lines = 0;
//     line = get_next_line(fd);
//     if (!line)
//         free_line(line, "Error\nMap is empty!!!\n");
//     len = ft_strlen(line);
//     if (line[len - 1] == '\n')
//     {
//         len--;
//         line[len] = '\0';
//     }
//     while (line)
//     {
//         if (line[len] == '\n')
//             line[len] = '\0';
//         if (len != ft_strlen(line))
//             free_line(line, "Error\nOh sorry the map is not rectangular!!\n");
//         free(line);
//         line = get_next_line(fd);
//         nb_lines++;
//     }
//     return (nb_lines);
// }

// int count_repeat(const  char *line, char c)
// {
//     int count;

//     count = 0;
//     while (*line)
//     {
//         if (*line == c)
//             count++;
//         line++;
//     }
//     return (count);
// }

// void exit_with_error(char **map, const char *msg)
// {
//     int i;

//     i = 0;
//     while (map[i])
//     {
//         free(map[i]);
//         i++;
//     }
//     free(map);
//     perror(msg);
//     exit(1);
// }

// int    is_valid_character(char *line)
// {
//     int i;

//     i = 0;
//     while (line[i])
//     {
//         if ((line[i] != 'P') && (line[i] != 'C') && (line[i] != 'E') && (line[i] != '1') && (line[i] != '0') && (line[i] != '\n'))
//             return (1);
//         i++;
//     }
//     return (0);
// }

// void    check_map_characters(char **ptr)
// {
//     int P = 0, C = 0, E = 0, i = 0;

//     while (ptr[i])
//     {
//         if (is_valid_character(ptr[i]) == 1)
//             exit_with_error(ptr, "Error:Invalid character!!!\n");
//         P += count_repeat(ptr[i], 'P');
//         C += count_repeat(ptr[i], 'C');
//         E += count_repeat(ptr[i], 'E');
//         i++;
//     }
//     if (P != 1)
//     {
//         printf("%d\n", P);
//         exit_with_error(ptr, "Error:The number of player is incorrect!!!\n");
//     }
//     if (C < 1)
//         exit_with_error(ptr, "Error:The number of collectible is incorrect!!!\n");
//     if (E != 1)
//         exit_with_error(ptr, "Error:The number of the map exit is incorrect!!!\n");
// }

// int    is_wall(char *line, char c)
// {
//     size_t len;
//     int i;

//     len = ft_strlen(line);
//     i = 0;
//     if (line[len - 1] == '\n')
//     {
//         len--;
//         line[len] = '\0';
//     }
//     if (c == 's' && (line[0] != '1' || line[len - 1] != '1'))
//         return (1);
//     if ((c == 't' || c == 'b'))
//     {
//         while (line[i])
//         {
//             if (line[i] != '1')
//                 return (1);
//             i++;
//         }
//     }
//     return (0);
// }

// void check_walls(char **ptr)
// {
//     int i;
//     char    *prev_line;

//     i = 0;
//     if (is_wall(ptr[0], 't') == 1)
//         exit_with_error(ptr, "Error:Wall problem!!!\n");
//     while (ptr[i])
//     {
//         if (is_wall(ptr[i], 's') == 1)
//             exit_with_error(ptr, "Error:Wall problem!!!\n");
//         prev_line = ptr[i];
//         i++;
//     }
//     if (is_wall(prev_line, 'b') == 1)
//         exit_with_error(ptr, "Error:Wall problem!!!\n");
// }

// void    handle_input(char *path)
// {
//     int fd;
//     int nb_lines;
//     char    *line;
//     char    **ptr;
//     int i;

//     i = 0;
//     is_valid_path_ext(path);
//     fd = open(path, O_RDONLY);
//     nb_lines = is_rectangular(fd);
//     close(fd);
//     ptr = malloc(sizeof(char *) * (nb_lines + 1));
//     fd = open(path, O_RDONLY);
//     line = get_next_line(fd);
//     while (line)
//     {
//         ptr[i] = line;
//         line = get_next_line(fd);
//         i++;
//     }
//     ptr[i] = NULL;
//     close(fd);
//     check_walls(ptr);
//     check_map_characters(ptr);
// }
// but tjhe problem that i dont know how to use images on my my map i want to raplce the 1s by wall img and the so on ....   in simple abd step by step plz and not to long plz


look at my code : 
int main(int argc, char **argv)
{
    void    *mlx;
    void    *win;
    char    **map;
    if (argc < 2)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    map = handle_input(argv[1]);
    mlx = mlx_init();
    if (!mlx)
    {
        perror("Error initializing MiniLibX");
        return (0);
    }
    win = mlx_new_window(mlx, 800, 600, "so long");
    if (!win)
    {
        perror("Error creating window");
        return (0);
    }
    mlx_loop(mlx);
    return (0);
}     now i want to display emages in the map u nw may program it take as a parameter the path of the file that contain my map : 1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111  then i check is this map valid (rectangular, contain one p one E and at least one C ...) and when i find it valide i put it in an array of strings u know every line as a string so the handel in put return it so now i think i should do somthing to apear the images one the window i dont know how could help me to put just one image in simple way and explain the steps plz 









oh sory i forget to give u the code : int main(int argc, char **argv)
{
    void    *mlx;
    void    *win;
    char    **map;
    if (argc < 2)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    map = handle_input(argv[1]);
    mlx = mlx_init();
    if (!mlx)
    {
        perror("Error initializing MiniLibX");
        return (0);
    }
    win = mlx_new_window(mlx, 800, 600, "so long");
    if (!win)
    {
        perror("Error creating window");
        return (0);
    }
    mlx_loop(mlx);
    return (0);
}   with this code i just appear a black window :(












































    #include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <stdio.h>

static void free_line(char *line, const char *msg)
{
    free(line);
    perror(msg);
    exit(1);
}

int    is_rectangular(int fd)
{
    char    *line;
    size_t     len;
    int nb_lines;

    nb_lines = 0;
    line = get_next_line(fd);
    if (!line)
        free_line(line, "Error\nMap is empty!!!\n");
    len = ft_strlen(line);
    if (line[len - 1] == '\n')
    {
        len--;
        line[len] = '\0';
    }
    while (line)
    {
        if (line[len] == '\n')
            line[len] = '\0';
        if (len != ft_strlen(line))
            free_line(line, "Error\nOh sorry the map is not rectangular!!\n");
        free(line);
        line = get_next_line(fd);
        nb_lines++;
    }
    return (nb_lines);
}

int count_repeat(const  char *line, char c)
{
    int count;

    count = 0;
    while (*line)
    {
        if (*line == c)
            count++;
        line++;
    }
    return (count);
}

void exit_with_error(char **map, const char *msg)
{
    int i;

    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
    perror(msg);
    exit(1);
}

int    is_valid_character(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if ((line[i] != 'P') && (line[i] != 'C') && (line[i] != 'E') && (line[i] != '1') && (line[i] != '0') && (line[i] != '\n'))
            return (1);
        i++;
    }
    return (0);
}

void    check_map_characters(char **ptr)
{
    int P = 0, C = 0, E = 0, i = 0;

    while (ptr[i])
    {
        if (is_valid_character(ptr[i]) == 1)
            exit_with_error(ptr, "Error:Invalid character!!!\n");
        P += count_repeat(ptr[i], 'P');
        C += count_repeat(ptr[i], 'C');
        E += count_repeat(ptr[i], 'E');
        i++;
    }
    if (P != 1)
    {
        printf("%d\n", P);
        exit_with_error(ptr, "Error:The number of player is incorrect!!!\n");
    }
    if (C < 1)
        exit_with_error(ptr, "Error:The number of collectible is incorrect!!!\n");
    if (E != 1)
        exit_with_error(ptr, "Error:The number of the map exit is incorrect!!!\n");
}

int    is_wall(char *line, char c)
{
    size_t len;
    int i;

    len = ft_strlen(line);
    i = 0;
    if (line[len - 1] == '\n')
    {
        len--;
        line[len] = '\0';
    }
    if (c == 's' && (line[0] != '1' || line[len - 1] != '1'))
        return (1);
    if ((c == 't' || c == 'b'))
    {
        while (line[i])
        {
            if (line[i] != '1')
                return (1);
            i++;
        }
    }
    return (0);
}

void check_walls(char **ptr)
{
    int i;
    char    *prev_line;

    i = 0;
    if (is_wall(ptr[0], 't') == 1)
        exit_with_error(ptr, "Error:Wall problem!!!\n");
    while (ptr[i])
    {
        if (is_wall(ptr[i], 's') == 1)
            exit_with_error(ptr, "Error:Wall problem!!!\n");
        prev_line = ptr[i];
        i++;
    }
    if (is_wall(prev_line, 'b') == 1)
        exit_with_error(ptr, "Error:Wall problem!!!\n");
}

char    **handle_input(char *path)
{
    int fd;
    int nb_lines;
    char    *line;
    char    **ptr;
    int i;

    i = 0;
    is_valid_path_ext(path);
    fd = open(path, O_RDONLY);
    nb_lines = is_rectangular(fd);
    close(fd);
    ptr = malloc(sizeof(char *) * (nb_lines + 1));
    if (!ptr)
        exit_with_error(ptr, "Error: Memory allocation failed!");
    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
     while (line)
    {
        ptr[i] = strdup(line);  // Corrected: Copy the line into ptr[i] using strdup
        if (!ptr[i])            // Check if strdup failed
            exit_with_error(ptr, "Error: Memory allocation for line failed!");
        free(line);             // Free the original line
        line = get_next_line(fd);
        i++;
    }
    ptr[i] = NULL;
    close(fd);
    check_walls(ptr);
    check_map_characters(ptr);
    return (ptr);
}
