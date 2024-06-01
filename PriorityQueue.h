#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <algorithm>
#include <stdexcept>

template<typename T>
class PriorityQueue {
private:
    std::vector<T> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void push(T data) {
        heap.push_back(data);
        heapifyUp(heap.size() - 1);
    }

    T pop() {
        if (heap.empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        T data = heap.front();
        std::swap(heap.front(), heap.back());
        heap.pop_back();
        heapifyDown(0);
        return data;
    }

    bool isEmpty() const {
        return heap.empty();
    }

    T top() const {
        if (heap.empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        return heap.front();
    }
};

#endif // PRIORITYQUEUE_H
