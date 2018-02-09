/* Gavin Smith & Liam Durant
 * COMP 40
 * 2/12/18
 * uarray2.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "uarray.h"
#include "uarray2.h"
#include "assert.h"

#define T UArray2_T

struct T {
        int height; 
        int width;
        int dataSize;
        UArray_T ray;
};

T UArray2_new (int width, int height, int dataSize) 
{
if (height * width * dataSize==0) {
assert(0);
}
  T uStruct = (T)malloc(20);
  assert(uStruct);
  uStruct->ray = UArray_new(height * width, dataSize);
  uStruct->height = height;
  uStruct->width = width;
  uStruct->dataSize = dataSize;
return uStruct;
} 

void *  UArray2_at( T UArray2, int col, int row) {
assert(UArray2);
int index=row*(UArray2->width) + col;
if (col >= UArray2->width || row >= UArray2->height || row < 0 || col < 0) {
printf("w: %d h: %d \nc: %d r: %d \n", UArray2->width, UArray2->height, row, col);
assert(0);
}

return UArray_at(UArray2->ray, index);
}

int UArray2_width(T UArray2) {
         assert(UArray2);
         return UArray2->width; 
}
 
int UArray2_height(T UArray2) {
        assert(UArray2);
        return UArray2->height;
}

void UArray2_free(T * UArray2) {
UArray_free(&(*UArray2)->ray);
free(*UArray2);
}

int UArray2_size(T UArray2) {
assert(UArray2);
return UArray2->dataSize;
}

void UArray2_map_row_major(T UArray2, void apply(int col, int row, T array, 
void * val, void *cl), void *cl) 
{
assert(UArray2);
assert(apply);

for (int r = 0; r < UArray2->height; r++) {
        for (int c = 0; c < UArray2->width; c++) {
apply(c, r, UArray2, UArray2_at(UArray2, c, r), cl);
}
}

}

void UArray2_map_col_major(T UArray2, void apply(int col, int row,
T array, void *val, void *cl), void *cl) 
{
assert(UArray2);
assert(apply);

for (int c = 0; c < UArray2->width; c++) {
        for (int r = 0; r < UArray2->height; r++) {
printf("r: %d c: %d\n", c, r);
apply(c, r, UArray2, UArray2_at(UArray2, c, r), cl);
}
}

}


