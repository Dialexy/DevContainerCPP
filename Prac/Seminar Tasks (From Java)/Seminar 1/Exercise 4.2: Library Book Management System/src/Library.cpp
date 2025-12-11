#include <iostream>
#include <string>
#include <unordered_map>


class Library {

    private:
        std::unordered_map<std::string, Book> books;

    public:
        void addBook(const Book& book) {
            std::string isbn = book.getISBN();

            if (books.find(isbn) != books.end()) {
                std::cout << "This book is already in the library.\n";
            }
            else {
                books[isbn] = book;
                std::cout << "Book added successfully.\n";
            }
        }

        Book* findBook(const std::string& isbn) {
            auto it = books.find(isbn);

            if (it != books.end()) {
                return &(it->second);
            }

            return nullptr;

        }
};
