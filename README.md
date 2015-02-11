# The-Game-of-Life
Conway's Game of Life is a game that simulates cells living and dying as "generations" continue. The cells follows these four rules- 

1. Any live cell with fewer than two live neighbours dies, as if caused by under-population.
2. Any live cell with two or three live neighbours lives on to the next generation.
3. Any live cell with more than three live neighbours dies, as if by overcrowding.
4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

Generations are simulated as the 'X's which represent alive cells and the '-'s represent dead cells.

##Instructions 
1. Open the command window
2. Change the directory to src 
3. Type 'make' into the command line
4. Type ./gameoflife.exe
5. Enter in the width, height, the density of the grid, and whether or not you want pauses between generations
