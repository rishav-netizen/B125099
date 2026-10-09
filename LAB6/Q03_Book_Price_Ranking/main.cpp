#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
        string title;
        double price;

    public:
        Book(string t, double p) : title(t), price(p) {}

        bool operator<(const Book& b) const {
            if (price != b.price)
                return price < b.price;
            return title < b.title;   // equal price -> smaller title is smaller
        }

        void display() const {
            cout << "\"" << title << "\" (Rs. " << price << ")";
        }
};

int main() {
    Book b1("C++ Primer", 899), b2("Java Basics", 799), b3("Python Guide", 799);

    cout << "b1 = ";
    b1.display();
    cout << endl;
    cout << "b2 = ";
    b2.display();
    cout << endl;
    cout << "b3 = ";
    b3.display();
    cout << endl;

    cout << "b2 < b1 ? " << (b2 < b1 ? "true" : "false") << endl;
    cout << "b2 < b3 ? " << (b2 < b3 ? "true" : "false")
         << "  (same price, \"Java Basics\" < \"Python Guide\")" << endl;
    return 0;
}
