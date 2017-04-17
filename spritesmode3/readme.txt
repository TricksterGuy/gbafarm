This demo showcases basic mode3 usage with sprites.

The only difference for sprite usage in mode3 is the addition of --for_bitmap.

This reduces the amount of sprite graphics memory you have in half, since in mode 3 you only get half the sprite graphics memory. It also offsets all sprite tile ids by 512 for you.

This demo also showcases an animated sprite.  When nin10kit detects an image with multiple frames it also outputs a separate array of pointers to each frame in the graphic.

Credits
dog.gif: http://s20.photobucket.com/user/dragonqueen9204/library/?view=recent&page=1
