# Cub3D
Cub3D is a simple raycasting game using the mlx library

---
## Todo
### Bonus
- Doors

---
## Features
### Mandatory
- Parsing .cub file for colors and sprites
- Parsing .cub file for the map
- Set floor and ceiling color based on .cub file
- Set Player starting direction based on letter in map
- Render walls by raycasting
- Walk in 4 directions
- Rotate with arrow keys
- Directional textures
### Bonus
- Wall Collision
- Rotate with the mouse
- Animated Sprites
- Minimap
### Extra
- FPS counter
- Timer
- Player can walk in 8 directions
- Player can Run
- Player can Jump
- Player can Crouch
- Map sizes up to 1 Megabyte (1000x1000)
- Player can collect Treasure
- Vertical Aiming
- Fullscreen
- Barrels
- Lights
- Weapon pickups
- Weapon Animations
- Stabs and bullets kill Enemies
- Ammo system
- Shooting Enemies
- Animated Enemies
- HP system
- Score system
- Level end elevator
- End level screen
- You died screen

---

## Missing Features
- Moving Enemies, We are not allowed to use random, so random movement is hard to do
- sounds and music, require functions that we are not allowed to use sadly
- floor textures, breaks the mandatory subject, it needs to be a solid color defined in the .cub file
- skybox, breaks the mandatory subject, it needs to be a solid color defined in the .cub file
- Start Menu, Breaks the mandatory subject since it needs to start with the .cub file passed as an argument

---
## Bugs
- none?

---
## Usage
1. Simply clone or download the repository
2. Run `make` in the cloned directory
3. Start the game with `./cub3d maps/level.cub`

---
[This project is part of the studies at 42](https://42.fr/en/homepage/)
