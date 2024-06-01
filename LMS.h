#ifndef LMS_H
#define LMS_H

#include "LinkedList.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "BST.h"
class Student;
class Teacher;
class Course;
class LMS {
public:
    void addStudent(std::string username, std::string password, int id);
    void addTeacher(std::string username, std::string password, int id);
    void addCourse(int id, std::string name, std::string desc, std::string teacherUsername);
    void enrollStudentInCourse(std::string studentUsername, int courseID);
    void removeStudentFromCourse(std::string studentUsername, int courseID);
    void listStudents() const;
    void listTeachers() const;
    void listCourses() const;
    bool loginStudent(std::string username, std::string password, int id);
    bool loginTeacher(std::string username, std::string password, int id);
    Student findStudentById(int id) const;
    Teacher findTeacherById(int id) const;
    Course findCourseById(int id) const;
    void printStudent(Student& student);


    BST<Student> students;
    BST<Teacher> teachers;
    BST<Course> courses;



    void printCourse(Course &course);
};

#endif // LMS_H
