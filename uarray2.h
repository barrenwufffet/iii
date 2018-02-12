/* Gavin Smith & Liam Durant
 * COMP 40
 * 2/6/18
 * uarray2.h
 */

#ifndef UARRAY2_INCLUDED
#define UARRAY2_INCLUDED

#define T UArray2_T
typedef struct T *T;

T UArray2_new(int width, int height, int dataSize);
void *  UArray2_at(T UArray2, int col, int row);
int UArray2_width(T UArray2); 
int UArray2_height(T UArray2);
void UArray2_free(T * UArray2);
int UArray2_size(T UArray2);
void UArray2_map_row_major(T UArray2, void apply(int col, int row,
        T array, void *val, void *cl), void *cl);
void UArray2_map_col_major(T UArray2, void apply(int col, int row,
        T array, void *val, void *cl), void *cl);


#undef T
#endif
