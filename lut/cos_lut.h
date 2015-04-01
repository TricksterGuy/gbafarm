/*
 * Exported with nin10kit v1.0
 * Invocation command was nin10kit -mode=lut -func=cos,int.22,0,360,0.25,1 cos_lut --log=4 
 * Time-stamp: Monday 12/15/2014, 20:44:31
 * 
 * Look up table Information
 * -------------------------
 * Function: cos Type: int.22 Range: [0, 360] Step: 0.25
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * 
 * All bug reports / feature requests are to be sent to Brandon (bwhitehead0308@gmail.com)
 */

#ifndef COS_LUT_H
#define COS_LUT_H

extern const int cos_table[1441];
#define COS_TABLE_SIZE 1441
#define COS_TABLE_FIXED_LENGTH 22
#define COS_TABLE_BEGIN ((0 << 22) | 0x000000)
#define COS_TABLE_END ((360 << 22) | 0x000000)
#define COS_TABLE_STEP ((0 << 22) | 0x100000)

#endif

