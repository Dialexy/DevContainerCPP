#include "Record.cpp"

class LinkedList {
    private:
        Node* head;
        Node* tail;
        size_t size;

    public:

        LinkedList(Node* head, Node* tail, size_t size) {
            this->head = head;
            this->tail = tail;
            this->size = size;
        }

        LinkedList() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        LinkedList(LinkedList &other) {
            head = nullptr;
            tail = nullptr;
            size = 0;

            Node* current = other.head;
            while (current != nullptr) {
                pushBack(current->data);
                current = current->next;
            }
        }

        LinkedList &operator=(const LinkedList &other) {
            if (this != &other) {
                Node* current = head;
                while (current != nullptr) {
                    Node* next = current->next;
                    delete current;
                    current = next;
                }

                head = nullptr;
                tail = nullptr;
                size = 0;
                current = other.head;

                while(current != nullptr) {
                    pushBack(current->data);
                    current = current->next;
                }
            }
            return *this;
        }

        ~LinkedList() {
            Node* current = head;
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            head = nullptr;
        }

        void pushFront(const Record &rec) {
            Node* newNode = new Node{rec, nullptr, head};

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }

            else {
                head->prev = newNode;
                head = newNode;
            }

            size++;
        };

        void pushBack(const Record &rec) {
            Node* newNode = new Node{rec, tail, nullptr};

            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }

            else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        };

        bool removeById(int id) {
            Node* current = head;
            while (current != nullptr) {
                if (current->data.getId() == id) {

            if (current->prev != nullptr) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }

            if (current->next != nullptr) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }

            delete current;
            size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

        Record* find(int id) {
            Node* current = head;
            while (current != nullptr) {
                if (current->data.getId() == id) {
                    return &(current->data);
            }
            current = current->next;
        }
        return nullptr;
    }

        void printForward() const {
            Node* current = head;
            while (current != nullptr) {
                std::cout << "Name: " << current->data.getName()
                    << "ID: " << current->data.getId()
                    << std::endl;

                current = current->next;
            }
        };

        void printBackward() const {
            Node* current = tail;
            while (current != nullptr) {
                std::cout << "Name: " << current->data.getName()
                    << "ID: " << current->data.getId()
                    << std::endl;

                current = current->prev;
            }
        };

        void insertAfter(int id, const Record &rec) {
            Node* current = head;
            while (current != nullptr) {
                if (current->data.getId() == id) {
                    Node* newNode = new Node{rec, current, current->next};

                    if (current->next != nullptr) {
                        current->next->prev = newNode;
                    }
                    else {
                        tail = newNode;
                    }

                    current->next = newNode;
                    size++;
                    return;
                }
                current = current->next;
            }
        };
};
