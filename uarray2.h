/* Gavin Smith & Liam Durant
 * COMP 40
 * 2/6/18
 * uarray2.h
 */

#ifdef UARRAY2_H_
#define UARRAY2_H_

#define T uarray2_T
typedef struct T *T;
 
T * uarray2_new(int height, int width, int dataSize);
void * uarray2_at(T uarray2, int row, int col);
int uarray2_width(T uarray2); 
int uarray2_height(T uarray2);
void uarray2_free(T * uarray2);
void uarray2_map_row_major(T uarray2, void apply(int row, int col,
        T array, void *cl), void *cl);
void uarray2_map_col_major(T uarray2, void apply(int row, int col,
        T array, void *cl), void *cl);

#undef T
#endif
