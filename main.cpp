#include <iostream>
#include <iomanip>
#include "StudentManager.h"
#include "InputHelpers.h"

// These lines let Dev-C++ build everything by compiling only main.cpp
#include "Student.cpp"
#include "InputHelpers.cpp"
#include "StudentManager.cpp"

using namespace std;

int main()
{
    cout << fixed << setprecision(2);

    StudentManager manager;
    manager.loadFromFile();

    int choice;

    do
    {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Sort and Display Students\n";
        cout << "7. Show Statistics\n";
        cout << "8. Save and Exit\n";
        choice = readInt("Enter your choice: ", 1, 8);

        if (choice == 1)
            manager.addStudent();
        else if (choice == 2)
            manager.viewStudents();
        else if (choice == 3)
            manager.searchStudent();
        else if (choice == 4)
            manager.updateStudent();
        else if (choice == 5)
            manager.deleteStudent();
        else if (choice == 6)
            manager.sortAndDisplay();
        else if (choice == 7)
            manager.showStatistics();
        else if (choice == 8)
        {
            manager.saveToFile();
            cout << "Exiting program...\n";
        }

    } while (choice != 8);

    return 0;
}
