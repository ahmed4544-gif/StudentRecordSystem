#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    int rollNumber;
    std::string name;
    std::string department;
    int semester;
    float cgpa;

public:
    void setData(int r, std::string n, std::string d, int s, float c);

    int getRollNumber();
    std::string getName();
    std::string getDepartment();
    int getSemester();
    float getCGPA();

    void displayData();
};

// Comparison functions used by std::sort
bool compareByCGPA(Student a, Student b);   // highest CGPA first
bool compareByName(Student a, Student b);   // A to Z

#endif
