#include <iostream>
using namespace std;

// Create class Employee
class Employee {
    private:
        int employeeID;
        string employeeName;
        double salary;

    public:
        void acceptDetails() {
            cout << "Enter Employee ID: ";
            cin >> employeeID;
            cin.ignore();
            cout << "Enter Employee Name: ";
            getline(cin, employeeName);
            cout << "Enter Salary: ";
            cin >> salary;
        }

        void displayDetails() {
            cout << "ID: " << employeeID << " | Name: " << employeeName 
                << " | Salary: ₹" << salary << endl;
        }

        double getSalary() {
            return salary;
        }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    // Dynamically allocate an array of n Employee objects
    Employee* empArray = new Employee[n];
    double totalSalary = 0.0;
    int highestIndex = 0;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Employee " << (i + 1) << " ---\n";
        empArray[i].acceptDetails();
        
        totalSalary += empArray[i].getSalary();
        
        // Find highest salary while traversing
        if (empArray[i].getSalary() > empArray[highestIndex].getSalary()) {
            highestIndex = i;
        }
    }

    cout << "\n--- All Employee Details ---\n";
    for (int i = 0; i < n; i++) {
        empArray[i].displayDetails();
    }

    cout << "\n--- Statistics ---\n";
    cout << "Employee with Highest Salary:\n";
    empArray[highestIndex].displayDetails();
    
    cout << "Average Salary: ₹" << (totalSalary / n) << endl;

    // Properly release the dynamically allocated array
    delete[] empArray;
    empArray = nullptr;

    return 0;
}
