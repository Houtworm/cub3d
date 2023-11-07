# Cub3D
Cub3D is a simple raycasting game using the mlx library

---
## Todo
### Parsing
- Flood fill the map starting from the player to check if it is a closed map
- Check if all needed elements are present in the closed part of the map
### Bonus
- Doors
- Minimap
### Extra
- Help screen
- End level screen
- You died screen
- Zoom with right mouse button
- Moving Enemies
- Score system
- Levels
- Start Menu // breaks mandatory subject
- Skybox // Breaks mandatory subject
- Sounds // need forbidden functions
- Music // need forbidden functions

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

---
## Bugs
- Player can get too close to walls
- Player walks twice as fast when holding W and A or W and D

---
## Usage
1. Simply clone or download the repository
2. Run `make` in the cloned directory
3. Start the game with `./cub3d`

---
[This project is part of the studies at 42](https://42.fr/en/homepage/)
