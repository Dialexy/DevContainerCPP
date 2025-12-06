#include <iostream>

class Matrix {

    private:
        int r;
        int c;
        int** array;

    public:

        Matrix() {
            r = 0;
            c = 0;
            array = nullptr;
        }

        Matrix(int rows, int cols) {
            r = rows;
            c = cols;

            array = new int*[rows];
            for (int i = 0; i < rows; i++) {
                array[i] = new int[cols];
           }

            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    array[i][j] = 0;
                }
            }
        }

        Matrix(const Matrix &other) {
            this->r = other.r;
            this->c = other.c;

            array = nullptr;
            array = new int*[r];
            for (int i = 0; i < r; i++) {
                array[i] = new int[c];
            }

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    array[i][j] = other.array[i][j];
                }
            }
        }

        ~Matrix() {
            for (int i = 0; i < r; i++) {
                delete[] array[i];
            }

            delete[] array;
        }

        int get(int r, int c) const {
            if (r > 0 && r < this->r && c > 0 && c < this->c) {
                return array[r][c];
            }
        }

        void set(int r, int c, int value) {
            if (r > 0 && r < this->r && c > 0 && c < this->c) {
                array[r][c] = value;
            }
            else {
                std::cerr << "The index is out of bounds";
            }
        }

        void fill(int value) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    array[i][j] = value;
                }
            }
        }

        Matrix add(const Matrix& other) const {
            if (r != other.r || c != other.c) {
                throw std::invalid_argument("matrix dimensions do not match");
            }

            Matrix result(r,c);

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    result.array[i][j] = array[i][j] + other.array[i][j];
                }
            }

            return result;
        }

        void print() {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    std::cout << array[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
};

