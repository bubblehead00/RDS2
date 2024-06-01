#ifndef BSTNODE_H
#define BSTNODE_H

template <typename T>
class BSTNode {
public:
    T data;
    BSTNode* left;
    BSTNode* right;

    BSTNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

#endif
