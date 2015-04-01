#include <stdio.h>
#include "sin_lut.h"
#include "cos_lut.h"

typedef int fixed32;
#define FIXED32(in, dec) ((in) << 22) | (dec))
#define FIXED_TO_INT(fixed) ((fixed) >> 22 & 0x7FFFFF)

fixed32 fixed_point_add(fixed32 a, fixed32 b)
{
	return a + b;
}

fixed32 fixed_point_mult(fixed32 a, fixed32 b)
{
	return ((long)a * (long)b) >> 22;
}

int main(void)
{
	int i = 0;
	for (fixed32 value = SIN_TABLE_BEGIN; value <= SIN_TABLE_END; 
		 value += SIN_TABLE_STEP, i++)
	{
		fixed32 sin = sin_table[i];
		fixed32 cos = cos_table[i];
		fixed32 sinx2 = fixed_point_mult(sin, sin);
		fixed32 cosx2 = fixed_point_mult(cos, cos);
		fixed32 one = fixed_point_add(sinx2, cosx2);
		
		printf("%d %x => sin: %x cos: %x sin**2: %x cos**2: %x one: %x\n", i, value,
		       sin, cos, sinx2, cosx2, one);		
	}
}
