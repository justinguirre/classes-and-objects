#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;

    Book(string t, string a, int y) : title(t), author(a), year(y) {}
};

class Library {
private:
    vector<Book> books;

public:
    void add(string title, string author, int year) {
        books.push_back(Book(title, author, year));
        cout << "Successfully added " << title << "! :D\n==============================" << endl;
    }

    void show() {
        if (books.empty()) {
            cout << "There are no books in this library :(\n==============================" << endl;
            return;
        }
        cout << "Books in this library:\n" << endl;
        cout << left << setw(30) << "Title" << setw(20) << "Author" << setw(6) << "Year" << endl;
        for (auto &book : books) {
            cout << left << setw(30) << book.title << setw(20) << book.author << setw(6) << book.year << endl;
        }
    }

    void search(string title) {
        for (auto &book : books) {
            if (book.title == title) {
                cout << "Book found! :D\n" << left << setw(30) << "Title" << setw(20) << "Author" << setw(6) << "Year" << endl;
                cout << left << setw(30) << book.title << setw(20) << book.author << setw(6) << book.year << endl;
                return;
            }
        }
        cout << "Book not found! :( Make sure the spelling, capitalization, and punctuation of your search query are correct.\n==============================" << endl;
    }
};

int main() {
    Library library;
    int option;
    string title = "none";
    string author = "none";
    int year = 0;

    while (true) {
        cout << "\n=========[MY LIBRARY]=========" << endl;
        cout << "[1] Add Book" << endl;
        cout << "[2] Show All Books" << endl;
        cout << "[3] Search Library" << endl;
        cout << "[4] Exit\n------------------------------" << endl;
        cout << "INPUT: ";
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1:
                cout << "==========[NEW BOOK]==========\n*Required" << endl; 
                do {
                    cout << "Title*: ";
                    getline(cin, title);
                } while (title == "none");
                do {
                    cout << "Author*: ";
                    getline(cin, author);
                } while (author == "none");
                do {
                    cout << "Year*: ";
                    cin >> year;
                } while (year == 0);
                cout << "Adding book..." << endl;
                library.add(title, author, year);

                title = "none";
                author = "none";
                year = 0;
                break;
            
            case 2:
                library.show();
                break;

            case 3:
                cout << "==========[SEARCH]==========\n*Required" << endl;
                do {
                    cout << "Title*: ";
                    getline(cin, title);
                } while (title == "none");

                library.search(title);
                break;

            case 4:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid option >:( Try again.";
        }
    }
    return 0;
};