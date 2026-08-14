#include <iostream>

using namespace std;

// Create class Product
class Product {
    private:
        int id;
        string name;
        double price;
        int quantity;

    public:
        void input() {
            cout << "Enter Product ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Product Name: ";
            getline(cin, name);
            cout << "Enter Price: ";
            cin >> price;
            cout << "Enter Quantity: ";
            cin >> quantity;
        }

        double getProductCost() {
            return price * quantity;
        }

        void displayCost() {
            cout << "Product: " << name << " (ID: " << id
                << ") | Total Cost: $" << getProductCost() << endl;
        }
};

int main() {
    int n;
    cout << "Enter the number of products: ";
    cin >> n;

    // Dynamically allocate memory for n Product objects
    Product* inventory = new Product[n];
    double overallValue = 0.0;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Product " << (i + 1) << " ---\n";
        inventory[i].input();
    }

    cout << "\n--- Inventory Details ---\n";
    for (int i = 0; i < n; i++) {
        inventory[i].displayCost();
        overallValue += inventory[i].getProductCost();
    }

    cout << "\nOverall Inventory Value: $" << overallValue << endl;

    // Use delete[] after processing all objects
    delete[] inventory;
    inventory = nullptr;

    return 0;
}
