#include <iostream>

using namespace std;

// Create class Book
class Book {
    private:
        int id;
        string title;
        string author;
        double price;

    public:
        void input() {
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore(); // Clear buffer before taking string input, so that i can accept spaces
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter Price: ";
            cin >> price;
        }

        void display() {
            cout << "\n--- Book Details ---\n";
            cout << "ID: " << id << endl;
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Price: ₹" << price << endl;
        }
};

int main() {
    // Dynamically create a single Book object
    Book* myBook = new Book;

    // Use -> operator to access member functions
    myBook->input();
    myBook->display();

    // Release dynamically allocated object
    delete myBook;  
    myBook = nullptr;
    
    return 0;
}
