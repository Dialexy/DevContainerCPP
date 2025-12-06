#include <iostream>
#include <vector>

class Matrix {


    private:
        int r;
        int c;
        int** emptyArray;
        int** array;


    public:

        Matrix() {
            for (int i = 0; i < r; i++) {
                emptyArray[i] = new int[c];
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    emptyArray[i][j] = 0;
                }
            }
        }

        Matrix(int rows, int cols) {
            r = rows;
            c = cols;

            for (int i = 0; i < rows; i++) {
                array[i] = new int[cols];
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    array[i][j] = 0;
                }
            }
        }

        Matrix(Matrix &oldRows, Matrix &oldCols) const {

        }

        ~Matrix() {
            for (int i = 0; i < r; i++) {
                delete[] array[i];
            }

            delete[] array;
        }
};

