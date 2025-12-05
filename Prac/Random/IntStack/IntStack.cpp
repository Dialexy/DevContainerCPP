#include <iostream>

class IntStack {

    private:

        int size;
        int top;
        int* arrPtr;


    public:

        IntStack (int capacity) {
            size = capacity;
            top = -1;
            arrPtr = new int[capacity];
        }

        ~IntStack() {
            delete[] arrPtr;
        }

        void push(int value) {
            if (top < size - 1) {
                top++;
                arrPtr[top] = value;
            }
            else {
                std::cout << "The stack is full.";
            }
        }

        int pop() {
            int value;
            if (top >= 0) {
                value = arrPtr[top];
                top--;
                return value;
            }
            else {
                std::cerr << "The stack is empty.";
                return -1;
            }
        }

        bool isEmpty() const {
            return top == -1;
        }

        bool isFull() const {
            return top == (size - 1);
        }

        void print() {
            for (int i = 0; i <= top; i++) {
                std::cout << arrPtr[i] << " ";
            }

            std::cout << std::endl;
        }
};
