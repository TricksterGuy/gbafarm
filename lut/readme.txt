This demo showcases nin10kit's lookup table generation functionality.

The export.sh just generates two look up tables for sin and cos.  The demo just shows the property that sin(x) ** 2 + cos(x) ** 2 == 1 note all calculations are in fixed point.

Breaking down the export commands.

nin10kit --mode=lut --func=sin,int.22,0,360,0.25,1 sin_lut

1. Generate a lookup table for the sin function.
2. int.22 means I want the type to be a fixed point type with 32 bits. 22 of those bits being represented for the fractional portion.
3. 0 is the start value
4. 360 is the end value
5. 0.25 is the step value so generate entries in the lut in 0.25 increments from 0 to 360 inclusive.
6. the 1 specifies that the values generated are in degrees.

Same deal for cos_lut.

nin10kit will export #defines for the begin, end, and step values converted to whatever representation you specified here a fixed point int with 22 bits fractional portion.

