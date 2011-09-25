#include <iostream>
using namespace std;


class Matrix {
private:
  int width;
  int height;
  int ** mat;
  
public:
  Matrix(int width, int height) : width(width), height(height) {
    mat = new int * [height];
    for (int i = 0; i < height; ++i) {
      mat[i] = new int [width];
    }
  }

  ~Matrix() {
    for (int i = 0; i < height; ++i) {
      delete [] mat[i];
    }

    delete [] mat;
  }

  void print() {
    for (int i = 0 ; i < height; ++i) {
      for ( int j = 0; j < width; ++j) {
        printf("%6d", mat[i][j]);
      }
      printf("\n");
    }
  }

  void turnNinty() {
    for(int i = 0; i < height; ++i) {
      for (int j = 0; j < width; ++j) {
        
      }
    }
  }
};
