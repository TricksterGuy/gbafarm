This demo showcases basic mode4 usage with multiple images

There are 3 images and the export.sh exports them all at once.  This will give you a global palette and image arrays that are designed to work with the global palette generated.

The algorithm used should be decent enough to not cause too much color loss.  You should only export images who will appear at the same screen at once.  This means you shouldn't export everything including your title and game over screens as you won't be displaying your in game images and title screen images at the same time.

in imageinfo.c you can customize where the images are drawn.

Compare the output of this demo to mode4multipalette.

