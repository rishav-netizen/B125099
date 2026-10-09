#include <iostream>
using namespace std;

class InventoryItem {
    private:
        int productID;
        double unitPrice;
        int quantity;

    public:
        InventoryItem(int id = 0, double price = 0, int qty = 0)
            : productID(id), unitPrice(price), quantity(qty) {}

        InventoryItem operator+(const InventoryItem& o) const {
            if (productID == o.productID && unitPrice == o.unitPrice) {
                return InventoryItem(productID, unitPrice, quantity + o.quantity);
            }
            cout << "Cannot combine: product ID or unit price mismatch!\n";
            return *this;   // unchanged copy; original objects untouched
        }

        void display() const {
            cout << "ID: " << productID << ", Price: Rs. " << unitPrice
                << ", Qty: " << quantity;
        }
};

int main() {
    InventoryItem i1(101, 50.0, 20), i2(101, 50.0, 15), i3(102, 50.0, 10);

    cout << "i1 = "; i1.display(); cout << endl;
    cout << "i2 = "; i2.display(); cout << endl;
    cout << "i3 = "; i3.display(); cout << endl;

    InventoryItem combined = i1 + i2;
    cout << "i1 + i2 = "; 
    combined.display(); 
    cout << endl;

    InventoryItem bad = i1 + i3;   // incompatible IDs
    cout << "i1 + i3 = "; 
    bad.display(); 
    cout << " (unchanged copy)" << endl;

    cout << "Originals intact: i1 = "; i1.display(); cout << endl;
    return 0;
}
