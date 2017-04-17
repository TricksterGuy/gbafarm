This demo shows 4bpp sprites in 1D mode.

The three sprites are an 64x64 image, 32x32 image, and 8x8 image.

The three images are converted to tiles 64, 16, and 1 tiles respectively each set of tiles has their own a 16 bit color palette.

nin10kit then forms the best 16 palette banks from these sets of tiles, merging palettes if necessary.

nin10kit then forms the output sprite array with all of the tiles sequentially.  Calculates the sprite offsets and other properties (palette id, shape, size, etc) and emit #defines

Credits

blue8x8: Ripped from Pokemon Fire Red / Leaf Green
bowser4x4: https://www.mariowiki.com/File:Yoshibowser.png
thing1x1: Made by me

