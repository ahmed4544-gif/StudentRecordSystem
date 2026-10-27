#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include <vector>
#include "Student.h"

class StudentManager
{
private:
    std::vector<Student> students;

    // Returns the position of a student in the vector, or -1 if not found
    int findIndex(int roll);

public:
    bool rollExists(int roll);

    void addStudent();
    void viewStudents();
    void searchStudent();
    void updateStudent();
    void deleteStudent();
    void sortAndDisplay();
    void showStatistics();

    void saveToFile();
    void loadFromFile();
};

#endif
