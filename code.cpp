#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class to store details of each book
class Book {
private:
    string title;
    string author;
    int id;
    bool isBorrowed;

public:
    // Constructor
    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isBorrowed = false;
    }

    // Display book details
    void displayBook() {
        cout << "ID: " << id << " | Title: " << title << " | Author: " << author;
        cout << " | Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }

    // Getters
    int getId() { return id; }
    string getTitle() { return title; }
    bool getStatus() { return isBorrowed; }

    // Borrow and return book functions
    void borrowBook() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << "Book '" << title << "' has been borrowed.\n";
        } else {
            cout << "Book is already borrowed!\n";
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << "Book '" << title << "' has been returned.\n";
        } else {
            cout << "This book was not borrowed.\n";
        }
    }
};

// Library class to manage books
class Library {
private:
    vector<Book> books;
    int bookCounter;

public:
    // Constructor
    Library() {
        bookCounter = 1;
    }

    // Add a new book
    void addBook(string title, string author) {
        books.push_back(Book(bookCounter, title, author));
        cout << "Book added successfully with ID: " << bookCounter << endl;
        bookCounter++;
    }

    // Display all books
    void displayBooks() {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "\n---- Library Books ----\n";
        for (Book &b : books) {
            b.displayBook();
        }
        cout << "------------------------\n";
    }

    // Search for a book by title
    void searchBook(string title) {
        for (Book &b : books) {
            if (b.getTitle() == title) {
                cout << "Book Found: ";
                b.displayBook();
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Borrow a book by ID
    void borrowBook(int bookId) {
        for (Book &b : books) {
            if (b.getId() == bookId) {
                b.borrowBook();
                return;
            }
        }
        cout << "Book ID not found.\n";
    }

    // Return a book by ID
    void returnBook(int bookId) {
        for (Book &b : books) {
            if (b.getId() == bookId) {
                b.returnBook();
                return;
            }
        }
        cout << "Book ID not found.\n";
    }
};

// Main function to run the library system
int main() {
    Library library;
    int choice;
    string title, author;
    int bookId;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Borrow Book\n5. Return Book\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character after entering choice

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                library.addBook(title, author);
                break;

            case 2:
                library.displayBooks();
                break;

            case 3:
                cout << "Enter book title to search: ";
                getline(cin, title);
                library.searchBook(title);
                break;

            case 4:
                cout << "Enter book ID to borrow: ";
                cin >> bookId;
                library.borrowBook(bookId);
                break;

            case 5:
                cout << "Enter book ID to return: ";
                cin >> bookId;
                library.returnBook(bookId);
                break;

            case 6:
                cout << "Exiting Library System. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
