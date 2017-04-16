# gbafarm
A bunch of sample gba games showcasing various graphical features of the gba and features of nin10kit the image exporter for use in developing homebrew applications for GBA, DS, and 3DS.

## Build environment
These demos are more geared specifically towards CS2110 students and have their own build environment.
If you are using devkitpro just drop the sources and headers in their appropriate folders and replace the Makefile with devkitpro's.

Otherwise for completeness here are the steps to set up the build environment

```bash
sudo add-apt-repository ppa:tricksterguy87/ppa-gt-cs2110
sudo apt-get update
sudo apt-get install gcc-arm-none-eabi cs2110-vbam-sdl cs2110-gba-linker-script nin10kit
```

Troubleshooting if there is an error about not being able to find -lc you will need to install the libnewlib-arm-none-eabi package

## To run a demo
1. Ensure that nin10kit (at least v1.7) is installed see https://github.com/TricksterGuy/nin10kit.
2. Run export.sh which will run commands to set up the demo, including exporting images or generating look up tables.
3. Open export.sh to see a similar command you can use in your development.

