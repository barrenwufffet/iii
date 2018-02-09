/* Gavin Smith & Liam Durant
 * COMP 40
 * 2/6/18
 * bit2.h
 */

#ifndef BIT2_INCLUDED
#define BIT2_INCLUDED

#define T Bit2_T
typedef struct T *T;
 
T  Bit2_new(int width, int height);
int Bit2_put(T Bit2, int col, int row, int bitnum);
int Bit2_get(T Bit2, int col, int row);
int Bit2_width(T Bit2); 
int Bit2_height(T Bit2);
void Bit2_free(T * Bit2);
void Bit2_map_row_major(T Bit2, void apply(int col, int row,
        T bitarr, int bitval, void *cl), void *cl);
void Bit2_map_col_major(T Bit2, void apply(int col, int row,
        T bitarr, int bitval, void *cl), void *cl);

#undef T
#endif
