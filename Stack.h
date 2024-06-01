#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::vector<T> stack;

public:
    void push(T data) {
        stack.push_back(data);
    }

    T pop() {
        if (stack.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        T data = stack.back();
        stack.pop_back();
        return data;
    }

    bool isEmpty() const {
        return stack.empty();
    }

    T top() const {
        if (stack.empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return stack.back();
    }
};

#endif // STACK_H
