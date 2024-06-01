#include "Student.h"
#include <iostream>
#include <list>

Student::Student(std::string name, std::string pass, int id) : studentName(name), studentPass(pass), id(id) {}


std::string Student::getName() const {
    return this->studentName;
}

int Student::getId() const {
    return this->id;
}

std::list<int> Student::getCourseIds() const {
    return this->courseIds;
}

bool Student::operator<(const Student& other) const { return id < other.id; }
bool Student::operator>(const Student& other) const { return id > other.id; }
bool Student::operator==(const Student& other) const { return id == other.id; }

void Student::enrollInCourse(int id) {
    courseIds.push_front(id);
}
bool Student::hasCourse(int id) {
    for (int courseId : courseIds) {
        if (courseId == id) {
            return true;
        }
    }
    return false;
}

void Student::removeCourse(int courseId) {
    courseIds.remove(courseId);
}

