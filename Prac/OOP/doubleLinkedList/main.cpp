#include <iostream>
#include "LinkedList.cpp"

int main() {
    std::cout << "--------- LINKED LIST THOROUGH TESTS ---------" << std::endl;

    LinkedList list;

    int passed = 0, failed = 0;

    // === Test 1: Empty list find ===
    if (list.find(1) == nullptr) { 
        std::cout << "PASS: find on empty list\n"; passed++; 
    } else { 
        std::cout << "FAIL: find on empty list\n"; failed++; 
    }

    // === Test 2: pushFront on empty list ===
    list.pushFront(Record(1, "Alice"));
    if (list.find(1)) { 
        std::cout << "PASS: pushFront on empty list\n"; passed++; 
    } else { 
        std::cout << "FAIL: pushFront on empty list\n"; failed++; 
    }

    // === Test 3: pushBack ===
    list.pushBack(Record(2, "Bob"));
    list.pushBack(Record(3, "Charlie"));
    if (list.find(2) && list.find(3)) { 
        std::cout << "PASS: pushBack\n"; passed++; 
    } else { 
        std::cout << "FAIL: pushBack\n"; failed++; 
    }

    // === Test 4: pushFront multiple ===
    list.pushFront(Record(0, "Zara"));
    if (list.find(0)) { 
        std::cout << "PASS: pushFront multiple\n"; passed++; 
    } else { 
        std::cout << "FAIL: pushFront multiple\n"; failed++; 
    }

    // === Test 5: insertAfter middle ===
    list.insertAfter(2, Record(4, "Diana"));
    if (list.find(4)) { 
        std::cout << "PASS: insertAfter middle\n"; passed++; 
    } else { 
        std::cout << "FAIL: insertAfter middle\n"; failed++; 
    }

    // === Test 6: insertAfter tail ===
    list.insertAfter(3, Record(5, "Eve"));
    if (list.find(5) && list.find(5)->getName() == "Eve") { 
        std::cout << "PASS: insertAfter tail\n"; passed++; 
    } else { 
        std::cout << "FAIL: insertAfter tail\n"; failed++; 
    }

    // === Test 7: insertAfter non-existent ===
    list.insertAfter(999, Record(6, "Frank")); // should do nothing
    if (list.find(6) == nullptr) { 
        std::cout << "PASS: insertAfter non-existent\n"; passed++; 
    } else { 
        std::cout << "FAIL: insertAfter non-existent\n"; failed++; 
    }

    // === Test 8: removeById head ===
    if (list.removeById(0) && list.find(0) == nullptr) { 
        std::cout << "PASS: removeById head\n"; passed++; 
    } else { 
        std::cout << "FAIL: removeById head\n"; failed++; 
    }

    // === Test 9: removeById tail ===
    if (list.removeById(5) && list.find(5) == nullptr) { 
        std::cout << "PASS: removeById tail\n"; passed++; 
    } else { 
        std::cout << "FAIL: removeById tail\n"; failed++; 
    }

    // === Test 10: removeById middle ===
    if (list.removeById(2) && list.find(2) == nullptr) { 
        std::cout << "PASS: removeById middle\n"; passed++; 
    } else { 
        std::cout << "FAIL: removeById middle\n"; failed++; 
    }

    // === Test 11: removeById non-existent ===
    if (!list.removeById(999)) { 
        std::cout << "PASS: removeById non-existent\n"; passed++; 
    } else { 
        std::cout << "FAIL: removeById non-existent\n"; failed++; 
    }

    // === Test 12: find + updateName ===
    Record* rec = list.find(1);
    if (rec) {
        rec->updateName("Alicia");
        if (rec->getName() == "Alicia") { 
            std::cout << "PASS: find + updateName\n"; passed++; 
        } else { 
            std::cout << "FAIL: find + updateName\n"; failed++; 
        }
    } else { 
        std::cout << "FAIL: find + updateName (record not found)\n"; failed++; 
    }

    // === Test 13: copy constructor ===
    list.pushBack(Record(7, "Grace"));
    LinkedList copyList(list);
    if (copyList.find(1) && copyList.find(7)) { 
        std::cout << "PASS: copy constructor\n"; passed++; 
    } else { 
        std::cout << "FAIL: copy constructor\n"; failed++; 
    }

    // === Test 14: assignment operator ===
    LinkedList assignList;
    assignList = list;
    if (assignList.find(1) && assignList.find(7)) { 
        std::cout << "PASS: assignment operator\n"; passed++; 
    } else { 
        std::cout << "FAIL: assignment operator\n"; failed++; 
    }

    // === Test 15: self-assignment ===
    assignList = assignList;
    if (assignList.find(1) && assignList.find(7)) { 
        std::cout << "PASS: self-assignment operator\n"; passed++; 
    } else { 
        std::cout << "FAIL: self-assignment operator\n"; failed++; 
    }

    // === Test 16: printForward ===
    std::cout << "\nList Forward:\n";
    list.printForward();

    // === Test 17: printBackward ===
    std::cout << "\nList Backward:\n";
    list.printBackward();

    // === Test 18: destructor (visual memory check via leak tool if desired) ===
    {
        LinkedList tempList;
        tempList.pushBack(Record(10, "Hank"));
        tempList.pushBack(Record(11, "Ivy"));
    } // tempList goes out of scope, destructor should free nodes
    std::cout << "\nPASS: destructor scope test (check for memory leaks manually)\n"; passed++;

    // === Test Summary ===
    std::cout << "\n--------- TEST SUMMARY ---------\n";
    std::cout << "Passed: " << passed << "\n";
    std::cout << "Failed: " << failed << "\n";
    std::cout << "--------------------------------\n";

    return 0;
}
