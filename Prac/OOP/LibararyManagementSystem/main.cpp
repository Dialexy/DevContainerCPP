#include "Book.h"
#include "Borrower.h"
#include <iostream>

int main() {
    std::cout << "=== Library Management System ===\n\n";
    
    // Create a book with 3 copies
    Book book("The C++ Programming Language", "978-0321563842", 3);
    
    std::cout << "Created book with " << book.getAvailableCopies() << " available copies.\n\n";
    
    // Create some borrowers
    Borrower alice("Alice Smith", "M001", "2024-12-01");
    Borrower bob("Bob Johnson", "M002", "2024-12-02");
    Borrower charlie("Charlie Brown", "M003", "2024-12-03");
    
    // Test borrowing books
    std::cout << "--- Borrowing Books ---\n";
    try {
        book.borrowBook(alice);
        std::cout << "Alice borrowed the book.\n";
        
        book.borrowBook(bob);
        std::cout << "Bob borrowed the book.\n";
        
        book.borrowBook(charlie);
        std::cout << "Charlie borrowed the book.\n";
        
        std::cout << "\nAvailable copies: " << book.getAvailableCopies() << "\n\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    
    // List all borrowers
    std::cout << "--- Current Borrowers ---\n";
    book.listBorrowers();
    
    // Test finding a borrower
    std::cout << "\n--- Finding Borrower ---\n";
    Borrower* found = book.findBorrower("M002");
    if (found) {
        std::cout << "Found: " << found->getName() << "\n";
    } else {
        std::cout << "Borrower not found.\n";
    }
    
    // Test returning a book
    std::cout << "\n--- Returning Book ---\n";
    try {
        book.returnBook("M001");
        std::cout << "Alice returned the book.\n";
        std::cout << "Available copies: " << book.getAvailableCopies() << "\n\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    
    // List borrowers after return
    std::cout << "--- Current Borrowers After Return ---\n";
    book.listBorrowers();
    
    // Test error handling - trying to borrow when full
    std::cout << "\n--- Testing Full Capacity ---\n";
    Borrower dave("Dave Wilson", "M004", "2024-12-04");
    Borrower eve("Eve Davis", "M005", "2024-12-05");
    
    try {
        book.borrowBook(dave);
        std::cout << "Dave borrowed the book.\n";
        
        book.borrowBook(eve);
        std::cout << "Eve borrowed the book.\n";
        
        // This should fail - no copies left
        Borrower frank("Frank Miller", "M006", "2024-12-06");
        book.borrowBook(frank);
        std::cout << "Frank borrowed the book.\n";
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    
    // Test error handling - returning non-existent borrower
    std::cout << "\n--- Testing Invalid Return ---\n";
    try {
        book.returnBook("M999");
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
    
    std::cout << "\n=== Program Complete ===\n";
    return 0;
}
