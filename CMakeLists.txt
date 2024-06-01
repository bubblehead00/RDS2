cmake_minimum_required(VERSION 3.28)
project(StudentManagementSystem)

set(CMAKE_CXX_STANDARD 26)

add_executable(StudentManagementSystem main.cpp
        LMS.cpp
        LMS.h
        Course.cpp
        Course.h
        Teacher.cpp
        Teacher.h
        Student.cpp
        Student.h
        PriorityQueue.h
        BST.h
        Queue.h
        Stack.h
        LinkedList.h
        BSTNode.h
)
