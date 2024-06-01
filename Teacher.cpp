#include "Teacher.h"

Teacher::Teacher(std::string u, std::string p, int id) : username(u), password(p), id(id) {}

std::string Teacher::getUsername() const {
    return this->username;
}

std::string Teacher::getPassword() const {
    return this->password;
}

int Teacher::getId() const {
    return this->id;
}

LinkedList<int > Teacher::getCourseList() const {
    return this->courseList;
}


bool Teacher:: operator==(const Teacher& other) const {
    return (this->id == other.id );
}
bool Teacher::operator>(const Teacher &other) const {
    return (this->id>other.id);
}
// Overload the in
// Overload the less than operator (for sorting, etc.)
bool Teacher:: operator<(const Teacher& other) const {
    return (this->id < other.id);
}
void Teacher::addCourseUnderTeacher(int course) {
    courseList.add(course);
}
bool Teacher::hasCourse(int Id){
    return this->courseList.find(Id);
}
