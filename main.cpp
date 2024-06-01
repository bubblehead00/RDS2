#include <iostream>
#include <string>
#include "LMS.h"

using namespace std;

LMS lms;

void studentMenu(string username, int id) {
    while (true) {
        cout << "\nStudent Menu" << endl;
        cout << "1. Enroll in Course" << endl;
        cout << "2. Remove Course" << endl;
        cout << "3. View My Courses" << endl;
        cout << "4. Logout" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;

        if (option == 1) {
            cout << "Enter course ID: ";
            int courseID;
            cin >> courseID;
            try {
                lms.enrollStudentInCourse(username, courseID);
                cout << "Enrolled in course successfully." << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
        } else if (option == 2) {
            cout << "Enter course ID: ";
            int courseID;
            cin >> courseID;
            try {
                lms.removeStudentFromCourse(username, courseID);
                cout << "Removed from course successfully." << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
        } else if (option == 3) {
            Student student = lms.findStudentById(id);
            if (student.getId() != 0) {
                for (auto node = student.getCourseList().getHead(); node != nullptr; node = node->next) {
                    cout << "Course ID: " << node->data.getId() << ", Name: " << node->data.getCourseName() << endl;
                }
            } else {
                cout << "Student not found." << endl;
            }
        } else if (option == 4) {
            break;
        } else {
            cout << "Invalid option, try again." << endl;
        }
    }
}

void teacherMenu(string username, int id) {
    while (true) {
        cout << "\nTeacher Menu" << endl;
        cout << "1. Add Course" << endl;
        cout << "2. List My Courses" << endl;
        cout << "3. View Students in My Course" << endl;
        cout << "4. Logout" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;

        if (option == 1) {
            cout << "Enter course ID: ";
            int courseID;
            cin >> courseID;
            cout << "Enter course name: ";
            string courseName;
            cin.ignore();  // To ignore newline character left in the input buffer
            getline(cin, courseName);
            cout << "Enter course description: ";
            string courseDesc;
            getline(cin, courseDesc);
            try {
                lms.addCourse(courseID, courseName, courseDesc, username);
                cout << "Course added successfully." << endl;
            } catch (const runtime_error& e) {
                cout << e.what() << endl;
            }
        } else if (option == 2) {
            Teacher teacher = lms.findTeacherById(id);
            if (teacher.getId() != 0) {
                for (auto node = teacher.getCourseList().getHead(); node != nullptr; node = node->next) {
                    cout << "Course ID: " << node->data.getId() << ", Name: " << node->data.getCourseName() << endl;
                }
            } else {
                cout << "Teacher not found." << endl;
            }
        } else if (option == 3) {
            cout << "Enter course ID: ";
            int courseID;
            cin >> courseID;
            Course course = lms.findCourseById(courseID);
            if (course.getId() != 0) {
                queue<int> q=course.getStudentList().toQueue();
                while(!q.empty()){
                    lms.printStudent(lms.findStudentById(q.front()));
                    q.pop();
                }
            } else {
                cout << "Course not found." << endl;
            }
        } else if (option == 4) {
            break;
        } else {
            cout << "Invalid option, try again." << endl;
        }
    }
}

void adminMenu() {
    while (true) {
        cout << "\nAdmin Menu" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Add Teacher" << endl;
        cout << "3. Add Course" << endl;
        cout << "4. List All Students" << endl;
        cout << "5. List All Teachers" << endl;
        cout << "6. List All Courses" << endl;
        cout << "7. View Students in Course" << endl;
        cout << "8. View Courses of Student" << endl;
        cout << "9. Logout" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;

        if (option == 1) {
            string username, password;
            int id;
            cout << "Enter student username: ";
            cin >> username;
            cout << "Enter student password: ";
            cin >> password;
            cout << "Enter student ID: ";
            cin >> id;
            lms.addStudent(username, password, id);
        } else if (option == 2) {
            string username, password;
            int id;
            cout << "Enter teacher username: ";
            cin >> username;
            cout << "Enter teacher password: ";
            cin >> password;
            cout << "Enter teacher ID: ";
            cin >> id;
            lms.addTeacher(username, password, id);
        } else if (option == 3) {
            int courseID;
            string courseName, courseDesc, teacherUsername;
            cout << "Enter course ID: ";
            cin >> courseID;
            cout << "Enter course name: ";
            cin.ignore();  // To ignore newline character left in the input buffer
            getline(cin, courseName);
            cout << "Enter course description: ";
            getline(cin, courseDesc);
            cout << "Enter teacher username: ";
            getline(cin, teacherUsername);
            lms.addCourse(courseID, courseName, courseDesc, teacherUsername);
        } else if (option == 4) {
            lms.listStudents();
        } else if (option == 5) {
            lms.listTeachers();
        } else if (option == 6) {
            lms.listCourses();
        } else if (option == 7) {
            cout << "Enter course ID: ";
            int courseID;
            cin >> courseID;
            Course course = lms.findCourseById(courseID);
            if (course.getId() != 0) {
                LinkedList<int>  studenetID=course.getStudentList();

                cout << "Course not found." << endl;
            }
        } else if (option == 8) {
            cout << "Enter student ID: ";
            int studentID;
            cin >> studentID;
            Student student = lms.findStudentById(studentID);
            if (student.getId() != 0) {
                for (auto node = student.getCourseList().getHead(); node != nullptr; node = node->next) {
                    cout << "Course ID: " << node->data.getId() << ", Name: " << node->data.getCourseName() << endl;
                }
            } else {
                cout << "Student not found." << endl;
            }
        } else if (option == 9) {
            break;
        } else {
            cout << "Invalid option, try again." << endl;
        }
    }
}

int main() {
    while (true) {
        cout << "\nLMS System" << endl;
        cout << "1. Login as Student" << endl;
        cout << "2. Login as Teacher" << endl;
        cout << "3. Login as Admin" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;

        if (option == 1) {
            string username, password;
            int id;
            cout << "Enter student username: ";
            cin >> username;
            cout << "Enter student password: ";
            cin >> password;
            cout << "Enter student ID: ";
            cin >> id;
            if (lms.loginStudent(username, password, id)) {
                studentMenu(username, id);
            } else {
                cout << "Invalid credentials, try again." << endl;
            }
        } else if (option == 2) {
            string username, password;
            int id;
            cout << "Enter teacher username: ";
            cin >> username;
            cout << "Enter teacher password: ";
            cin >> password;
            cout << "Enter teacher ID: ";
            cin >> id;
            if (lms.loginTeacher(username, password, id)) {
                teacherMenu(username, id);
            } else {
                cout << "Invalid credentials, try again." << endl;
            }
        } else if (option == 3) {
            adminMenu();
        } else if (option == 4) {
            break;
        } else {
            cout << "Invalid option, try again." << endl;
        }
    }




    return 0;
}
