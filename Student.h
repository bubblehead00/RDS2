#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "LinkedList.h"
#include "Course.h"
#include <list>
#include <queue>
using namespace std;
class Course;  // Forward declaration


class Student {
public:
    Student(std::string u, std::string p, int id);
    void removeCourse(int courseId);
    std::list<int> getCourseIds() const;
    void enrollInCourse(int id);
    std::string getName() const;
    std::string getPassword() const;
    int getId() const;
    LinkedList<Course> getCourseList() const;

    bool operator==(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator>(const Student& other)const;
    bool hasCourse(int id);
private:

    int id;
    std::string studentName;
    std::string studentPass;
    list<int> courseIds;


};

#endif // STUDENT_H
