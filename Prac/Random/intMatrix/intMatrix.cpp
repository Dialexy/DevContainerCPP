#include <iostream>

class intMatrix {

    private:

        int r;
        int c;
        int** array2D;


    public:

        intMatrix(int rows, int cols) {
            r = rows;
            c = cols;

            array2D = new int*[rows];
            for (int i = 0; i < rows; i++) {
                array2D[i] = new int[cols];
            }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) { 
                    array2D[i][j] = 0;
                }
            }
        }

        ~intMatrix() {
            for (int i = 0; i < r; i++) {
                delete[] array2D[i];
            }
            delete[] array2D;
        }

        void set(int row, int col, int value) {
            if (row >= 0 && row < r && col >= 0 && col < c) {
                array2D[row][col] = value;
            }
            else {
                std::cerr << "Index out of bounds." << std::endl;
            }
        }

        int get(int row, int col) const {
            if (row >= 0 && row < r && col >= 0 && col < c) {
                return array2D[row][col];
            }
            else {
                std::cerr << "Index out of bounds.";
                return -1;
            }
        }

        void print() {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    std::cout << array2D[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
};
