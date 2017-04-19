This demo showcases the --mode=tiles and --mode=map usage in 8bpp mode.

The downside of using --mode=0 is that you pass in your map images and then nin10kit forms a tileset from those images.
What if you wanted to modify the map image during the game?  For instance for dynamically changing the map, or making some tiles appear to be animated?
Another benefit is exporting your maps separately generates a tile graphics array for each file you create, making your binary bigger.

This is a 2 step export

1. Export your image(s) containing all of your tiles (tileset) using --mode=tiles.  WARNING all tiles present in the image(s) must be distinct.
2. Export all of your maps with --mode=map being sure to also pass in the same tileset(s) as the --tileset_image flag, they must appear in the same order.

A gif image with 3 frames gamemap.gif is passed in.  It is simply the same image as spiral.png except the 2nd frame is inverted, the third frame is also composed of simpler tiles.
A tileset named simple_tileset.png with all of the tiles contained in gamemap.gif.
