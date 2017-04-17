This demo showcases using an animation in mode4 (second way)

The difference between this demo and mode4animated is the use of the --split flag.
Using this flag in mode 4 export with multiple images/animation will not generate a global palette.  Here you will get X palettes one for each image/frame exported.

Though technically not useful in this case since gifs are already restricted to 256 colors. This is would probably be more useful for showing a full screen animation of a file type that is not already indexed since a global palette may lead to loss of quality ex. if one frame had a lot of color then more entries in the palette would be dedicated to that one frame.

The demo code just displays the frame and then copies its palette over with a delay added before switching.  Try using the up and down arrow keys to make the animation faster or slower.

source: https://giphy.com/gifs/cat-funny-cute-Qi8brOMchUtrO
