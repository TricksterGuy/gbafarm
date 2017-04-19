This demo showcases basic mode0 usage with multiple map images in 8bpp.

A gif image with 3 frames gamemap.gif is passed in.  It is simply the same image as spiral.png except the 2nd frame is inverted, the third frame is also composed of simpler tiles.

Again same process
1. All maps are converted to 256 bit color.
2. The tiles are extracted from the map and a tileset is formed.
3. The map data is then formed from matching each tile against the tileset.

This demo
1) Simply loads the generated palette banks into the graphics palette at 0x5000000
2) Stores the tileset (tiles graphics) in character block 0
3) Stores the map data in screen block 28
4) Sets up REG_DISPCNT to enable background 0
5) Sets the background 0 control register to point to the tile and map data.

