#include <stdio.h>
#include "mask.h"

// When completed this file will contain several versions of the
// mask() function and conditional compilation will be used to
// determine which version runs.  Each version will be named mask1,
// mask2, and so on. To select the version of the mask function to
// use, change the following declaration to the version of the mask()
// to be used.  All versions of mask() must produce a correct result.

// The provided Makefile also includes the possibility of creating an
// executable called "timemask-maskN" (replacing maskN with any
// version you'd like to test). You may compile it with "make
// timemask-maskN" then run "./timemask-maskN".

#ifndef MASK_VERSION
#define MASK_VERSION mask0
#endif

// You are only allowed to change the contents of this file with
// respect to improving the performance of this program. You may not
// change the data structure for each image or the parameters for the
// function mask. You may, however, change the structure of the code
// and the types/implementation of local variables (col, row, weight,
// etc.).


// You are required to document the changes you make in the README.txt
// file. For each entry in the README.txt file there is to be a
// version of the matching mask() function here such that the markers
// can see, and run if needed, the actual code that you used to
// produce your results for the logged change to the mask function.

static inline long mask0(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
  // first change is to make all function row major order

   int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image
  for (i = 0; i < cols; i++){
    for (j = 0; j < rows; j++) {
      newImage[i][j] = WEIGHT_CENTRE * oldImage[i][j];
      weight[i][j] = WEIGHT_CENTRE;
    }
  }
  
  // Count the cells to the top left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells immediately above
  for (i = 0; i < cols; i++) {
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[i][j] += oldImage[i][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the top right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the immediate left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows; j++) {
      newImage[i][j] += oldImage[col][j];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows; j++) {
      newImage[i][j] += oldImage[col][j];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the bottom left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[i][j] += oldImage[i][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[i][j] = newImage[i][j] / weight[i][j];
      check += newImage[i][j];
    }
  
  return check;




//Check if two images are identical
 // return baseMask(oldImage, newImage, rows, cols);
}

// For each version of mask you are testing duplicate the function
// below, rename it to a different name, and make your changes. To use
// the new version, change the #define above to use the current version.

static inline long mask1(long oldImage[N][N], long newImage[N][N], int rows, int cols) {

  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask0 by
  // making better use of caching.
   int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  //initialize the new image
  for (i = 0; i < cols; i++){
    for (j = 0; j < rows; j++) {
      newImage[i][j] = WEIGHT_CENTRE * oldImage[i][j];
      weight[i][j] = WEIGHT_CENTRE;
    }
  }
  
  // Count the cells to the top left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells immediately above
  for (i = 0; i < cols; i++) {
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[i][j] += oldImage[i][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the top right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the immediate left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows; j++) {
      newImage[i][j] += oldImage[col][j];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows; j++) {
      newImage[i][j] += oldImage[col][j];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the bottom left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[i][j] += oldImage[i][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[i][j] = newImage[i][j] / weight[i][j];
      check += newImage[i][j];
    }
  
  return check;


}
  


static inline long mask2(long oldImage[N][N], long newImage[N][N], int rows, int cols) {

  // TODO This function should contain code that produces the same
  // output as baseMask, but is expected to run faster than mask1 (or
  // mask0) by making better use of caching.

  int i, j;
  int col, row;
  long check = 0;

  long (*weight)[N] = calloc(N * N, sizeof(long));
  
  // //initialize the new image
  // for (i = 0; i < cols; i++){
  //   for (j = 0; j < rows; j++) {
  //     newImage[i][j] = WEIGHT_CENTRE * oldImage[i][j];
  //     weight[i][j] = WEIGHT_CENTRE;
  //   }
  // }
  
  // // Count the cells to the top left
  // for (i = 1; i < cols; i++) {
  //   col = i - 1;
  //   for (j = 1; j < rows; j++) {
  //     row = j - 1;
  //     newImage[i][j] += oldImage[col][row];
  //     weight[i][j]++;
  //   }
  // }


    //initialize the new image
  for (i = 0; i < cols; i++){
    for (j = 0; j < rows; j++) {
      newImage[i][j] = WEIGHT_CENTRE * oldImage[i][j];
      weight[i][j] = WEIGHT_CENTRE;
    
   
  
  // Count the cells to the top left
      int r1 = i;
      int c1 = j;
      if ((i != cols) || (j != rows)){
      newImage[i][j] += oldImage[cols][rows];
      weight[i][j]++;

    }
  }
}
  
  // Count the cells immediately above
  for (i = 0; i < cols; i++) {
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[i][j] += oldImage[i][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the top right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 1; j < rows; j++) {
      row = j - 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the immediate left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows; j++) {
      newImage[i][j] += oldImage[col][j];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the immediate right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows; j++) {
      newImage[i][j] += oldImage[col][j];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the bottom left
  for (i = 1; i < cols; i++) {
    col = i - 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells immediately below
  for (i = 0; i < cols; i++) {
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[i][j] += oldImage[i][row];
      weight[i][j]++;
    }
  }
  
  // Count the cells to the bottom right
  for (i = 0; i < cols - 1; i++) {
    col = i + 1;
    for (j = 0; j < rows - 1; j++) {
      row = j + 1;
      newImage[i][j] += oldImage[col][row];
      weight[i][j]++;
    }
  }

  // Produce the final result
  for (i = 0; i < cols; i++)
    for (j = 0; j < rows; j++) {
      newImage[i][j] = newImage[i][j] / weight[i][j];
      check += newImage[i][j];
    }
  
  return check;


}
long mask(long oldImage[N][N], long newImage[N][N], int rows, int cols) {
  return MASK_VERSION(oldImage, newImage, rows, cols);
}

