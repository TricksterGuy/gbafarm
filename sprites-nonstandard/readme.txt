This demo shows exporting non standard sprite sizes with nin10kit.

Note that this demo is strictly for advanced users who know what they are doing.

The preferred method of working with sprites is to give nin10kit properly sized images representing the sprites you want to use in your game, and nin10kit will give you the proper #defines to copy to OAM, essentially the tile-id offset, and the shape and size of the sprite. Currently these images must strictly be sized the same dimensions as the GBA allows for sprites.

A single sprite of size 48x64 is exported. Note to disable to strict dimension checks --force is passed in. The only #define that is given is the starting tile-id offset which should be used to identify where in the sprite graphics data the non standard image is.

The demo splits this in an inefficient manner, as a 32x64 and two 16x32 sprites (Technically one could use a 64x64 if the data was padded.).  The sprite's tiles are copied in proper order, by splitting the data and reforming it in 1D sprite order.  The same process can be used for images larger than the maximum sprite size of 64x64.

Note that in exporting with --force only 1D sprite tile mapping can be used.
