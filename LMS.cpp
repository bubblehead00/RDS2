#include "BST.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class LMS {
private:
    BST<Student> students;
    BST<Teacher> teachers;
    BST<Course> courses;
public:
    void printStudent(Student& student) {
        std::cout << "ID: " << student.getId() << ", Name: " << student.getName() << std::endl;
    }
    void printTeacher(Teacher& teacher){
        std::cout<< "ID: " << teacher.getId() << ", Name: " << teacher.getUsername() << std::endl;
    }
    void printCourse(Course& course){
        std::cout<< "ID: " << course.getId() << ", Name: " << course.getCourseName() << std::endl;
    }

    void addStudent(string username, string password, int id) {
        Student student(username, password, id);
        if (students.find(student)) {
            throw runtime_error("Student already exists");
        }
        students.insert(student);
    }

    void addTeacher(string username, string password, int id) {
        Teacher teacher(username, password, id);
        if (teachers.find(teacher)) {
            throw runtime_error("Teacher already exists");
        }
        teachers.insert(teacher);
    }

    void addCourse(int id, string name) {

        Course course(id, name);
        if (courses.find(course)) {
            throw runtime_error("Course already exists");
        }
        courses.insert(course);
    }

    void enrollStudentInCourse(int StudentID, int courseID) {
        if(students.find(StudentID)&&courses.find(courseID)){
            students.findNodeByID(StudentID)->data.enrollInCourse(courseID);
            courses.findNodeByID(courseID)->data.addStudent(StudentID);

        }else throw runtime_error("Student or Course not found");

    }

    void removeStudentFromCourse(int studentID, int courseID) {
        if(courses.findNodeByID(courseID)->data.hasStudent(studentID))
        courses.findNodeByID(courseID)->data.removeStudent(studentID);
        if(students.findNodeByID(studentID)->data.hasCourse((courseID)))
            students.findNodeByID(studentID)->data.removeCourse(courseID);

    }

    void listStudents() const {
        students.inOrderTraversal([](Student& s) {
            cout << "ID: " << s.getId() << ", Username: " << s.getName() << endl;
        });
    }

    void listTeachers() const {
        teachers.inOrderTraversal([](Teacher& t) {
            cout << "ID: " << t.getId() << ", Username: " << t.getUsername() << endl;
        });
    }

    void listCourses() const {
        courses.inOrderTraversal([](Course& c) {
            cout << "ID: " << c.getId() << ", Name: " << c.getCourseName() << endl;
        });
    }

    bool loginStudent(string username, string password, int id) {
        bool loggedIn = false;
        string pass, a;
        if (students.findNodeByID(id)->data.getName()== username && teachers.findNodeByID(id)->data.getPassword() == password) {
            loggedIn = true;
        }

        return loggedIn;
    }

    bool loginTeacher(string username, string password, int id) {
        bool loggedIn = false;
        string pass, a;
            if (teachers.findNodeByID(id)->data.getUsername()== username && teachers.findNodeByID(id)->data.getPassword() == password) {
                loggedIn = true;
            }

        return loggedIn;
    }

    Student findStudentById(int id) const {
        return students.findNodeByID(id)->data;
    }

    Teacher findTeacherById(int id) const {
        return teachers.findNodeByID(id)->data;
    }

    Course findCourseById(int id) const {
        return courses.findNodeByID(id)->data;
    }

};

