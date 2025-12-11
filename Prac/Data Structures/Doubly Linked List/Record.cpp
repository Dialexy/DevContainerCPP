#include <iostream>

class Record {

    private:
        int id;
        std::string name;

    public:
        Record(int id, const std::string& name) {
            this->id = id;
            this->name = name;
        }

        Record(const Record &other) {
            this->id = other.id;
            this->name = other.name;
        }

        int getId() { return id; }
        std::string getName() { return name; }
        void updateName(const std::string &newName) { name = newName; }
};

struct Node {
    Record data;
    Node* prev;
    Node* next;


    Node(const Record& rec, Node* p = nullptr, Node* n = nullptr)
        : data(rec), prev(p), next(n) {}
};
