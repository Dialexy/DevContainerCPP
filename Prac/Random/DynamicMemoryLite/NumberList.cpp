#include <iostream>

class NumberList {

    private:
        int size;
        int* arrPtr;

    public:
        NumberList(int n) {
            size = n;
            arrPtr = new int[n];

            for (int i = 0; i < size; i++) {
                arrPtr[i] = 0;
            }
        }

        ~NumberList() {
            delete[] arrPtr;
        }

        void set(int index, int value) {
            if (index >= 0 && index < size) {
                arrPtr[index] = value;
            } 
            else {
                std::cout << "Index out of bounds!\n"; //could use cerr
            }
        }

        int get(int index) const {
            if (index >= 0 && index < size) {
                return arrPtr[index];
            } 
            else {
                std::cout << "Index out of bounds!\n"; //could use cerr
                return -1;
            }
        }

        void print() const {
            for (int i = 0; i < size; i++) {
                std::cout << arrPtr[i] << " ";
            }

            std::cout << std::endl;
        }
};
