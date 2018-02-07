/* Gavin Smith & Liam Durant
 * COMP 40
 * 2/6/18
 * bit2.h
 */

#ifdef BIT2_H_
#define BIT2_H_

#define B bit2_T
typedef struct T *T;
 
T * bit2_new(int height, int width);
int bit2_put(T bit2, int bitnum, int row, int col);
int bit2_get(T bit2, int row, int col);
int bit2_width(T bit2); 
int bit2_height(T bit2);
void bit2_free(T * bit2);
void bit2_map_row_major(T bit2, void apply(int row, int col,
        T bitarr, int bitval, void *cl), void *cl);
void bit2_map_col_major(T bit2, void apply(int row, int col,
        T bitarr, int bitval, void *cl), void *cl);

#undef T
#endif