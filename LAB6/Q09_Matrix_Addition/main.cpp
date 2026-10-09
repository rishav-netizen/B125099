#include <iostream>
using namespace std;

class Matrix {
    private:
        int a[2][2];

    public:
        Matrix(int m00 = 0, int m01 = 0, int m10 = 0, int m11 = 0) {
            a[0][0] = m00; a[0][1] = m01;
            a[1][0] = m10; a[1][1] = m11;
        }

        Matrix operator+(const Matrix& m) const {
            Matrix result;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    result.a[i][j] = a[i][j] + m.a[i][j];
            return result;
        }

        void display() const {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++)
                    cout << a[i][j] << "\t";
                cout << endl;
            }
        }
};

int main() {
    Matrix m1(1, 2, 3, 4), m2(5, 6, 7, 8);

    cout << "m1:\n"; 
    m1.display();
    cout << "m2:\n"; 
    m2.display();

    Matrix m3 = m1 + m2;
    cout << "m1 + m2:\n"; 
    m3.display();

    cout << "m1 unchanged:\n"; 
    m1.display();
    return 0;
}
