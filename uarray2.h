#ifdef USEARRAY2_H_
#define USEARRAY2_H_

#define T UArray2_T;
 
T * UArray_new(int height, int width, int dataSize);

void * UArray2_at(T UArray2, int row, int col);
int UArray2_width(T UArray2); 
int UArray2_height(T UArray2);
int UArray2_height(T UArray2);
void UArray_free(T * UArray2);