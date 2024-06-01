#ifndef TEACHER_H
#define TEACHER_H

#include <string>
#include "LinkedList.h"
#include "Course.h"

class Teacher {
public:
    Teacher(std::string u, std::string p, int id);
    Teacher()=default;
    std::string getUsername() const;
    std::string getPassword() const;
    int getId() const;
    LinkedList<int> getCourseList() const;

    bool operator==(const Teacher& other) const;
    bool operator<(const Teacher& other) const;
    bool operator>(const Teacher& other) const;
    void addCourseUnderTeacher(int courseID);

private:
    std::string username;
    std::string password;
    int id;
    LinkedList<int> courseList;

    bool hasCourse(int Id);
};

#endif // TEACHER_H
