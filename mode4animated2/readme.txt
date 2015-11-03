This demo showcases using an animation in mode4 (second way)

The difference between this demo and mode4animated is the use of the -split flag.
Using this flag in mode 4 export with multiple images/animation will not generate a global palette.  Here you will get X palettes one for each image/frame exported.

This is more useful for showing a full screen animation since a global palette may lead to loss of quality ex. if one frame had a lot of color then more entries in the palette would be dedicated to that one frame.

The demo code just displays the frame and then copies its palette over with a delay added before switching.  Try using the up and down arrow keys to make the animation faster or slower.


