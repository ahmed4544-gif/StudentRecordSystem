#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student
{
private:
    int rollNumber;
    string name;
    string department;
    int semester;
    float cgpa;

public:
    void setData(int r, string n, string d, int s, float c)
    {
        rollNumber = r;
        name = n;
        department = d;
        semester = s;
        cgpa = c;
    }

    int getRollNumber() { return rollNumber; }
    string getName() { return name; }
    string getDepartment() { return department; }
    int getSemester() { return semester; }
    float getCGPA() { return cgpa; }

    void displayData()
    {
        cout << "\nRoll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Semester: " << semester << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

bool compareByCGPA(Student a, Student b)
{
    return a.getCGPA() > b.getCGPA();   
}

bool compareByName(Student a, Student b)
{
    return a.getName() < b.getName();  
}

class StudentManager
{
private:
    vector<Student> students;

  
    int findIndex(int roll)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getRollNumber() == roll)
                return i;
        }
        return -1;
    }

public:
    bool rollExists(int roll)
    {
        return findIndex(roll) != -1;
    }

    void addStudent()
    {
        int roll, semester;
        string name, department;
        float cgpa;

        cout << "Enter roll number: ";
        cin >> roll;

        if (rollExists(roll))
        {
            cout << "Error: Roll number already exists!\n";
            return;
        }

        cout << "Enter name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter department: ";
        getline(cin, department);

        cout << "Enter semester: ";
        cin >> semester;

        cout << "Enter CGPA: ";
        cin >> cgpa;

        Student s;
        s.setData(roll, name, department, semester, cgpa);
        students.push_back(s);

        cout << "Student added successfully!\n";
    }

    void viewStudents()
    {
        if (students.empty())
        {
            cout << "No student records found.\n";
            return;
        }
        for (int i = 0; i < students.size(); i++)
            students[i].displayData();
    }

    void searchStudent()
    {
        int option;
        cout << "Search by: 1. Roll Number  2. Name\n";
        cout << "Enter option: ";
        cin >> option;

        bool found = false;

        if (option == 1)
        {
            int roll;
            cout << "Enter roll number: ";
            cin >> roll;

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getRollNumber() == roll)
                {
                    students[i].displayData();
                    found = true;
                }
            }
        }
        else if (option == 2)
        {
            string name;
            cout << "Enter name: ";
            cin >> ws;
            getline(cin, name);

            for (int i = 0; i < students.size(); i++)
            {
                if (students[i].getName() == name)
                {
                    students[i].displayData();
                    found = true;
                }
            }
        }
        else
        {
            cout << "Invalid option.\n";
            return;
        }

        if (!found)
            cout << "Student not found.\n";
    }

    void updateStudent()
    {
        int roll;
        cout << "Enter roll number of the student to update: ";
        cin >> roll;

        int index = findIndex(roll);
        if (index == -1)
        {
            cout << "Student not found.\n";
            return;
        }

        cout << "\nCurrent record:";
        students[index].displayData();

        string name, department;
        int semester;
        float cgpa;

        cout << "\nEnter new name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter new department: ";
        getline(cin, department);

        cout << "Enter new semester: ";
        cin >> semester;

        cout << "Enter new CGPA: ";
        cin >> cgpa;

        /
        students[index].setData(roll, name, department, semester, cgpa);

        cout << "Student updated successfully!\n";
    }

    void deleteStudent()
    {
        int roll;
        cout << "Enter roll number of the student to delete: ";
        cin >> roll;

        int index = findIndex(roll);
        if (index == -1)
        {
            cout << "Student not found.\n";
            return;
        }

        students[index].displayData();

        char confirm;
        cout << "\nAre you sure you want to delete this student? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y')
        {
            students.erase(students.begin() + index);
            cout << "Student deleted successfully!\n";
        }
        else
        {
            cout << "Delete cancelled.\n";
        }
    }

   
    void sortAndDisplay()
    {
        if (students.empty())
        {
            cout << "No student records found.\n";
            return;
        }

        int option;
        cout << "Sort by: 1. CGPA (highest first)  2. Name (A to Z)\n";
        cout << "Enter option: ";
        cin >> option;

        vector<Student> sorted = students;  
        if (option == 1)
        {
            sort(sorted.begin(), sorted.end(), compareByCGPA);
        }
        else if (option == 2)
        {
            sort(sorted.begin(), sorted.end(), compareByName);
        }
        else
        {
            cout << "Invalid option.\n";
            return;
        }

        for (int i = 0; i < sorted.size(); i++)
            sorted[i].displayData();
    }

    void showStatistics()
    {
        if (students.empty())
        {
            cout << "No student records found.\n";
            return;
        }

        float total = 0;
        for (int i = 0; i < students.size(); i++)
            total += students[i].getCGPA();

        float average = total / students.size();

        cout << "\n===== Statistics =====\n";
        cout << "Total students: " << students.size() << endl;
        cout << "Average CGPA: " << average << endl;

       
        vector<Student> sorted = students;
        sort(sorted.begin(), sorted.end(), compareByCGPA);

        int count = 3;
        if (sorted.size() < 3)
            count = sorted.size();

        cout << "\nTop " << count << " students:\n";
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ". " << sorted[i].getName()
                 << " (Roll " << sorted[i].getRollNumber() << ")"
                 << " - CGPA: " << sorted[i].getCGPA() << endl;
        }
    }
};

int main()
{
    StudentManager manager;
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
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

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
            cout << "Exiting program...\n";
        else
            cout << "Invalid choice. Try again.\n";

    } while (choice != 8);

    return 0;
}
