/* Gavin Smith & Liam Durant
 * COMP 40
 * 2/12/18
 * sudoku.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "uarray2.h"
#include "assert.h"
#include "pnmrdr.h"
#include "except.h"



void solve(Pnmrdr_T image);
void sudokuCheck(int col, int row, UArray2_T array, void *val, void *cl);
void makeFalse(bool *ray);
void checkTrue(bool *ray);

int main(int argc, char * argv[]) 
{
  Pnmrdr_T image;    

  if ( argc == 1 ){
    TRY
      image = Pnmrdr_new(stdin);
    EXCEPT(Pnmrdr_Badformat);
    assert(EXIT_FAILURE);
    END_TRY;
    solve(image);
    Pnmrdr_free(&image);

  } else if (argc == 2) {
    FILE * greyscale=fopen(argv[1],"rb");
    if (greyscale==NULL) {
      fprintf(stderr, "ERROR: FILE DOES NOT EXIST\n");
      assert(0);
    }

    TRY
      image = Pnmrdr_new(greyscale);
    EXCEPT(Pnmrdr_Badformat);
    fprintf(stderr, "ERROR: INVALID FILE TYPE\n");
    assert(0);
    EXCEPT(Pnmrdr_Count)
      fprintf(stderr, "ERROR: WRONG NUMBER OF PIXELS READ\n");
    assert(0);
    END_TRY;
    
    solve(image);
    fclose(greyscale);
    Pnmrdr_free(&image);
  } else {

  fprintf(stderr, "ERROR: INVALID NUMBER OF ARGUMENTS\n");    
    assert(0);
  }

  return 0;
}

void solve (Pnmrdr_T image) 
{
  
  Pnmrdr_mapdata map;
  map = Pnmrdr_data(image);
 
  if (map.type!=2) {
    fprintf(stderr, "ERROR: INVALID MAP TYPE\n");
    assert(0);
  }
  if (map.width != 9 ||  map.height != 9)  {
     fprintf(stderr,"ERROR: INAVLID SUDOKU DIMENSIONS\n");
     assert(0);
  }
if (map.denominator != 9) {
     fprintf(stderr,"ERROR: INAVLID MAP DENOMINATOR (MUST BE 9)\n");
     assert(0);
 }

  UArray2_T  board = UArray2_new(9, 9, 4);
for ( unsigned c = 0; c < map.width; c++) {
  for ( unsigned r = 0; r < map.height; r++) {
    *((int *) UArray2_at(board, c, r))=Pnmrdr_get(image);
  }
 }

  bool* checkArray;
  checkArray = (bool *)malloc(sizeof(bool)*9);
  makeFalse(checkArray);

 
  UArray2_map_col_major(board, sudokuCheck, checkArray);
  printf("inbetween\n");
  UArray2_map_row_major(board, sudokuCheck, checkArray);
  printf("after\n");

UArray2_free(&board);
free(checkArray);
} 



void sudokuCheck(int col, int row, UArray2_T array, void *val, void *cl)
{
  (void) col;
  (void) row;
  (void) array;
  int value = *((int *) val);
  bool * boolArray = (bool *) cl;
  printf("bool before: %d\n", (boolArray)[value-1]);
  printf("value: %d\n", value);
  if(value < 1 || value > 9) {
    fprintf(stderr, "ERROR: NOT VALID VALUE FOR SUDOKU BOARD\n");
    exit(1);
  }
  if((boolArray)[value-1] == true) {
    fprintf(stderr, "Board is not solved correctly!\n");
    exit(1);
  }
  else {
    (boolArray)[value-1] = true;
  }
  checkTrue(boolArray); 
  printf("bool after: %d\n", (boolArray)[value-1]);
}

void makeFalse(bool *ray)
{
  for(int i = 0; i < 9; i++) {
    ray[i] = false;
  }
}

void checkTrue(bool *ray)
{
  int check = 0;
  for(int i = 0; i < 9; i++) {
    if((ray)[i] == true) {
      check++;
    }
  }
  if(check == 9) {
    makeFalse(ray);
  }
}


