This demo showcases basic mode4 usage with an image with transparency

Then the transparent color is chosen via specifying a hexcolor with --transparent. This forces palette entry 0 to become the transparent color.

The export commands specify blue to be the transparent color, Not shown in the demo, but any pixels that are transparent in the image are immediately turned to palette entry 0 during export.

You can replace the image with anything you want, just modify export.sh and modify the image passed into the program (change background.png to whatever image).
