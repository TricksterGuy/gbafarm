This demo showcases mode 0 usage with a transparent color in 4bpp mode.

In mode 0 (and tiles and map) modes when a transparent color is given, it forces this color to be palette entry 0 which is not drawn, it also forces tile 0 to be the empty tile.

This demo also showcases multiple map layers.  The first layer being the ground and the second being a set of trees.

And since the images have a lot of color nin10kit will detect there are more than 16 distinct palettes.  Pass --force and nin10kit will try its best to minimize color loss when forming the 16 palette banks.

Credit: RMXP's RTP
