*This project has been created as part of the 42 curriculum by **Khadija Lamachi (klamachi)**.*

# So Long

A small 2D game developed in **C** using the **MiniLibX** graphics library.

The goal is to collect all collectibles on the map and then reach the exit. The project focuses on window management, keyboard input, 2D rendering, map parsing, validation, and path checking.

## Screenshot

![So Long gameplay](screenshots/gameplay.png)

## Features

* 2D game rendered with MiniLibX
* Map parsing from `.ber` files
* Map validation and error handling
* Flood-fill path validation
* Collectibles and exit management
* Player movement using `W`, `A`, `S`, `D`
* Move counter displayed in the terminal
* Clean exit with `ESC` or the window close button

## Map Format

Maps use the following characters:

| Character | Meaning     |
| --------- | ----------- |
| `1`       | Wall        |
| `0`       | Empty space |
| `P`       | Player      |
| `C`       | Collectible |
| `E`       | Exit        |

A valid map must:

* Be rectangular
* Be completely surrounded by walls
* Contain exactly one player (`P`)
* Contain exactly one exit (`E`)
* Contain at least one collectible (`C`)
* Have a valid path allowing the player to collect all collectibles and reach the exit

Example:

```text
111111
100001
10C001
10P0E1
111111
```

## Controls

| Key   | Action     |
| ----- | ---------- |
| `W`   | Move up    |
| `A`   | Move left  |
| `S`   | Move down  |
| `D`   | Move right |
| `ESC` | Exit game  |

Each valid movement is counted and displayed in the terminal.

## Requirements

This project uses **MiniLibX** and requires the X11 development libraries on Linux.

Install the required dependencies:

```bash
sudo apt update
sudo apt install libx11-dev libxext-dev libbsd-dev
```

## Installation & Usage

Clone the repository:

```bash
git clone https://github.com/KhadijaLamachi/so_long.git so_long
cd so_long
```

Build the project:

```bash
make
```

The Makefile automatically builds the required MiniLibX library and `ft_printf` before linking the game.

Run the game with a `.ber` map:

```bash
./so_long maps/map.ber
```

You can also try:

```bash
./so_long maps/map1.ber
```

## Makefile Commands

```bash
make        # Build the project
make clean  # Remove object files
make fclean # Remove object files and the executable
make re     # Rebuild the project
```

## Project Structure

```text
.
├── ft_printf/
├── get_next_line/
├── maps/
├── minilibx-linux/
├── textures/
├── check_wall_characters.c
├── draw.c
├── flood_fill.c
├── free_close.c
├── handle_input.c
├── so_long.c
├── so_long.h
├── utils.c
└── Makefile
```

## Resources

* [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
