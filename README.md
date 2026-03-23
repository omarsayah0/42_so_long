*This project has been created as part of the 42 curriculum by oaletham.*

# so_long

## Description
**so_long** is a small 2D game project from the 42 curriculum, built in C using the MiniLibX graphical library.

The main goal of the project is to create a simple playable game while learning how to:
- manage a graphical window,
- render textures and images,
- handle keyboard events,
- parse and validate a map,
- organize game logic cleanly in C.

The player must collect all collectibles on the map and then reach the exit while avoiding invalid moves and respecting the project rules.

## Bonus Features

The bonus version includes:
- enemy patrols / animated sprites / move counter on screen / different tiles / etc.


## Instructions

### Compilation
To build the mandatory version:
```bash
make
```

To build the bonus version:
```bash
make bonus
```

To remove object files:
```bash
make clean
```

To remove object files and executables:
```bash
make fclean
```

To rebuild everything:
```bash
make re
```

### Execution
Run the mandatory version with:
```bash
cd mand/./so_long maps/map.ber
```

If your project builds a separate bonus executable, run it with:
```bash
cd bonus/./so_long maps/map.ber
```

Replace `maps/map.ber` with the path to any map file.

### Map rules
The program checks that:
- the map is rectangular,
- the map is surrounded by walls,
- there is exactly 1 player (`P`),
- there is exactly 1 exit (`E`),
- there is at least 1 collectible (`C`),
- only valid characters are used (`0`, `1`, `C`, `E`, `P`, and enemy if bonus),
- all collectibles and the exit are reachable.

### Controls

- `W` / `A` / `S` / `D` or arrow keys: move player
- `ESC`: close the game window
- Red cross on window: quit the game

## Output

Add your screenshots in this section later.

### Example 1 (Mandatory Version)

<img width="1358" height="509" alt="image" src="https://github.com/user-attachments/assets/14c53bbc-0207-4f86-a97a-74f3272723f7" />

### Example 2 (Exit Opens After Collecting All Items)
<img width="1350" height="500" alt="image" src="https://github.com/user-attachments/assets/08301878-df4b-43c3-9b41-d90f15a85c0f" />


### Example 3 (Bonus Version)
<img width="1912" height="783" alt="image" src="https://github.com/user-attachments/assets/ee176d46-e7cf-4014-95b1-3d664ba86192" />


## Resources

### Project / Topic References
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [X11 Event Handling Basics](https://tronche.com/gui/x/xlib/events/)
- [C Graphics Programming Basics](https://www.geeksforgeeks.org/graphics-in-c/)
- [Game Loop Explanation](https://gameprogrammingpatterns.com/game-loop.html)
- [Map Parsing Concepts in C](https://en.wikipedia.org/wiki/Parsing)

### Suggested Classic References
- [MiniLibX GitHub Repository](https://github.com/42Paris/minilibx-linux)
- [Harm-Smits 42 Docs](https://harm-smits.github.io/42docs/)
- [Manual Pages (man7.org)](https://man7.org/linux/man-pages/)
- [Tile-based Game Explanation](https://en.wikipedia.org/wiki/Tile-based_video_game)
- [Keyboard and Event Handling in X11](https://tronche.com/gui/x/xlib/input/)

### AI Usage
AI was used as a support tool for:
- discussing project structure and file organization,
- improving code readability and folder layout,
- helping rewrite or clarify documentation,
- getting explanations about concepts related to parsing, rendering, and event handling.

