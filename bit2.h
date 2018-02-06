/* Gavin Smith & Liam Durant
 * COMP 40
 * 2/6/18
 * bit2.h
 */

#ifdef BIT2_H_
#define BIT2_H_

#define B bit2_B
typedef struct B *B;
 
T * bit2_new(int height, int width, int dataSize);
void * bit2_at(B bit2, int row, int col);
int bit2_width(B bit2); 
int bit2_height(B bit2);
int bit2_height(B bit2);
void bit2_free(B * bit2);
void bit2_map_row_major(B bit2, void apply(void *bit,
        void *cl), void *cl);
void bit2_map_col_major(B bit2, void apply(void *bit,
        void *cl), void *cl);

#undef T
#endif