#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "LinkedList.h"
#include "Student.h"
#include "Teacher.h"
using namespace std;
class Teacher;
class Student;
class Course {
public:
    Course(int id, std::string name, int  t);
    Course(int id, std::string name);
    void addStudent(int id);
    void removeStudent(int studentId);
    std::string getCourseName() const;
    int getId() const;
    void addTeacherUnderCourse(int teacher);
    void viewCourse() const;
    LinkedList<int> getStudentList() const;
    bool hasStudent(int Id);
    bool operator==(const Course& other) const;
    bool operator<(const Course& other) const;
    bool operator>(const Course& other) const;

private:
    int id;
    std::string courseName;
    int teacher = 0;
    LinkedList<int > studentList;

    bool removeTeacher();
};

#endif // COURSE_H
