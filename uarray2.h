/* Gavin Smith & Liam Durant
 * COMP 40
 * 2/6/18
 * uarray2.h
 */

#ifdef USEARRAY2_H_
#define USEARRAY2_H_

#define T UArray2_T
typedef struct T *T;
 
T * UArray_new(int height, int width, int dataSize);
void * UArray2_at(T UArray2, int row, int col);
int UArray2_width(T UArray2); 
int UArray2_height(T UArray2);
int UArray2_height(T UArray2);
void UArray2_free(T * UArray2);
void UArray2_map_row_major(T UArray2, void apply(void *value,
        void *cl), void *cl);
void UArray2_map_col_major(T UArray2, void apply(void *value,
        void *cl), void *cl);

#undef T
#endif
