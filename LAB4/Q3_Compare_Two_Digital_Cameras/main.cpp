#include <iostream>

using namespace std;

class Camera {
    private:
        string brand;
        string model;
        int megapixels;
        int storageCapacity;

    public:
        Camera()
        {

        }

        Camera(string b, string m, int mp, int storage) {
            brand = b;
            model = m;
            megapixels = mp;
            storageCapacity = storage;
        }

        void Input()
        {
            cout << "Brand: ";
            cin.ignore();
            getline(cin, brand);
            cout << "Model: ";
            cin >> model;
            cout << "Megapixels: ";
            cin >> megapixels;
            cout << "Storage(GB): ";
            cin >> storageCapacity;
        }


        friend void compareCamera(Camera c1, Camera c2);
};

void compareCamera(Camera c1, Camera c2) {
    Camera better = c1;

    if (c2.megapixels > c1.megapixels || (c2.megapixels == c1.megapixels && c2.storageCapacity > c1.storageCapacity)) 
    {
        better = c2;
    }

    cout << "\n\nDetails of the better camera are as follows:\n";
    cout << "Brand: " << better.brand << endl;
    cout << "Model: " << better.model << endl;
    cout << "Megapixels: " << better.megapixels << endl;
    cout << "Storage: " << better.storageCapacity << " GB\n";
}

int main() {
    Camera *cameras = new Camera[2];

    for (int i = 0; i < 2; i++)
    {
        cout << "\nEnter camera " << i + 1 << " details: \n";
        cameras[i].Input();
    }
    
    compareCamera(cameras[0], cameras[1]);

    return 0;
}