#ifndef QUEUE_H
#define QUEUE_H
#include<stdexcept>

#include <deque>

template<typename T>
class Queue {
private:
    std::deque<T> queue;

public:
    void enqueue(T data) {
        queue.push_back(data);
    }

    T dequeue() {
        if (queue.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T data = queue.front();
        queue.pop_front();
        return data;
    }

    bool isEmpty() const {
        return queue.empty();
    }

    T front() const {
        if (queue.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        return queue.front();
    }
};

#endif // QUEUE_H
