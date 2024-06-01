#include "Course.h"
#include <iostream>

Course::Course(int id, std::string name, int t) : id(id), courseName(name), teacher(t) {}

Course::Course(int id, std::string name) : id(id), courseName(name) {}

void Course::addStudent(int student) {
    studentList.add(student);
}

void Course::removeStudent(int studentId) {
    studentList.remove(studentId);
}

std::string Course::getCourseName() const {
    return this->courseName;
}

int Course::getId() const {
    return this->id;
}

LinkedList<int> Course::getStudentList() const {
    return this->studentList;
}

bool Course::operator==(const Course& other) const {
    return this->id == other.id;
}
bool Course::operator<(const Course& other) const {
    return this->id < other.id;
}
bool Course::operator>(const Course& other) const {
    return this->id > other.id;
}
void Course::addTeacherUnderCourse(int teacher) {
    this->teacher=teacher;
}
bool Course::removeTeacher(){
    this->teacher=0;
}

void Course::viewCourse() const {
    std::cout << "Name: " << this->courseName << " Id: " << this->id << std::endl;
}
bool Course::hasStudent(int Id) {
    return studentList.find(Id);
}