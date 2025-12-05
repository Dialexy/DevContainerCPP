#include <iostream>
#include <cstring>

class StringList {

    private:
        int size;
        char** list;


    public: 
        StringList(int n) {
            size = n;
            list = new char*[size];

            for (int i = 0; i < size; i++) {
                list[i] = new char[51];
                list[i][0] = '\0';
            }
        }


        ~StringList() {
            for (int i = 0; i < size; i++) {
                delete[] list[i];
            }
            delete[] list;
        }


        void set(int index, const char* text) {
            if (index >= 0 && index < size) {
                strncpy(list[index], text, 50);
                list[index][50] = '\0';
            }
            else {
                std::cerr << "Out of bounds index" << "\n";
            }
        }


        const char* get (int index) const {
            if (index >= 0 && index < size) {
                return list[index];
            }
            else {
                return nullptr;
            }
        }


        void print() const {
            for (int i = 0; i < size; i++) {
                std::cout << list[i] << std::endl;
            }
        }
};
