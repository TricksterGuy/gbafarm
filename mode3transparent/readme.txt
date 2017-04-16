This demo showcases basic mode3 usage with an image with transparency

Then the transparent color is chosen via specifying a hexcolor with --transparent. This givens a #define that is used in main.c to ignore pixels with the same color.

The export commands specify magneta to be the transparent color, Not shown in the demo, but any pixels that are transparent in the image are immediately turned to black during export.

You can replace the image with anything you want, just modify export.sh and modify the image passed into the program (change background.png to whatever image).
