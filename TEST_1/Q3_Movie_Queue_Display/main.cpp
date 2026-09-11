#include <iostream>

using namespace std;

class QueueDisplay 
{
    private:
        int size;
        int *ids;

    public:
        QueueDisplay(int n = 0)
        {
            size = n;

            if (size > 0)
            {
                ids = new int[size];
            }
            else
            {
                ids = nullptr;
            }
        }

        void insert(int index, int id)
        {
            if (index >= 0 && index < size)
            {
                ids[index] = id;
            }
        }

        void display()
        {
            for (int i = 0; i < size; i++)
            {
                cout << ids[i] << " ";
            }
            cout << endl;
        }

        friend void exchange(QueueDisplay &, QueueDisplay &);

        ~QueueDisplay()
        {
            delete[] ids;
            ids = nullptr;
        }
};

void exchange(QueueDisplay &q1, QueueDisplay &q2) 
{
    swap(q1.size, q2.size);
    swap(q1.ids, q2.ids);
}

int main()
{
    int n1, n2;

    cout << "Enter size of queue 1: ";
    cin >> n1;

    cout << "Enter size of queue 2: ";
    cin >> n2;

    QueueDisplay *q = new QueueDisplay[2]
    {
        QueueDisplay(n1), 
        QueueDisplay(n2)
    };

    cout << "\nEnter IDs for queue 1: ";
    int tempID;
    for (int i = 0; i < n1; i++)
    {
        cin >> tempID;
        q[0].insert(i, tempID);
    }

    cout << "\nEnter IDs for queue 2: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> tempID;
        q[1].insert(i, tempID);
    }

    cout << "\nBefore exchange:\n";
    cout << "Queue 1: ";
    q[0].display();
    cout << "Queue 2: ";
    q[1].display();
    
    exchange(q[0], q[1]);
    
    cout << "\nAfter exchange:\n";
    cout << "Queue 1: ";
    q[0].display();
    cout << "Queue 2: ";
    q[1].display();

    delete[] q;
    q = nullptr;

    return 0;
}