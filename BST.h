#ifndef BST_H
#define BST_H

#include "BSTNode.h"

template <typename T>
class BST {
private:
    BSTNode<T>* root;

    void insert(BSTNode<T>*& node, T value);
    bool find(BSTNode<T>* node, T value) const;
    void inOrderTraversal(BSTNode<T>* node, void (*visit)(T&)) const;
    BSTNode<T>* findNodeByID(BSTNode<T>* node, int id) const;

public:
    BST();
    void insert(T value);
    bool find(T value) const;
    void inOrderTraversal(void (*visit)(T&)) const;
    BSTNode<T>* getRoot() const;
    BSTNode<T>* findNodeByID(int id) const;

    bool find(int id) const;

    bool removeByID(int id);

    BSTNode<T> *removeNodeByID(BSTNode<T> *node, int id, bool &removed);
};

// Constructor for BST
template<typename T>
BST<T>::BST() : root(nullptr) {}

// Helper function to insert a value into the BST
template<typename T>
void BST<T>::insert(BSTNode<T>*& node, T value) {
    if (node == nullptr) {
        node = new BSTNode<T>(value);
    } else if (value < node->data) {
        insert(node->left, value);
    } else if (value > node->data) {
        insert(node->right, value);
    }
}

// Public function to insert a value into the BST
template<typename T>
void BST<T>::insert(T value) {
    insert(root, value);
}

// Helper function to find a value in the BST
template<typename T>
bool BST<T>::find(BSTNode<T>* node, T value) const {
    if (node == nullptr) {
        return false;
    } else if (value < node->data) {
        return find(node->left, value);
    } else if (value > node->data) {
        return find(node->right, value);
    } else {
        return true;
    }
}

// Public function to find a value in the BST
template<typename T>
bool BST<T>::find(T value) const {
    return find(root, value);
}

// Helper function for in-order traversal of the BST
template<typename T>
void BST<T>::inOrderTraversal(BSTNode<T>* node, void (*visit)(T&)) const {
    if (node != nullptr) {
        inOrderTraversal(node->left, visit);
        visit(node->data);
        inOrderTraversal(node->right, visit);
    }
}

// Public function for in-order traversal of the BST
template<typename T>
void BST<T>::inOrderTraversal(void (*visit)(T&)) const {
    inOrderTraversal(root, visit);
}

// Public function to get the root of the BST
template<typename T>
BSTNode<T>* BST<T>::getRoot() const {
    return root;
}

// Helper function to find a node by ID
template<typename T>
BSTNode<T>* BST<T>::findNodeByID(BSTNode<T>* node, int id) const {
    if (node == nullptr || node->data.getId() == id) {
        return node;
    } else if (id < node->data.getId()) {
        return findNodeByID(node->left, id);
    } else {
        return findNodeByID(node->right, id);
    }
}


// Public function to find a node by ID
template<typename T>
BSTNode<T>* BST<T>::findNodeByID(int id) const {
    return findNodeByID(root, id);
}

template<typename T>
bool BST<T>::find(int id) const {
    return findNodeByID(root, id) != nullptr;
}

template<typename T>
bool BST<T>::removeByID(int id) {
    bool removed = false;
    root = removeNodeByID(root, id, removed);
    return removed;
}

template<typename T>
BSTNode<T>* BST<T>::removeNodeByID(BSTNode<T>* node, int id, bool& removed) {
    if (node == nullptr) {
        return node; // Node not found, return nullptr
    }

    if (id < node->data.getId()) {
        node->left = removeNodeByID(node->left, id, removed);
    } else if (id > node->data.getId()) {
        node->right = removeNodeByID(node->right, id, removed);
    } else {
        // Node with the id found
        removed = true;
        if (node->left == nullptr) {
            BSTNode<T>* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            BSTNode<T>* temp = node->left;
            delete node;
            return temp;
        }

        // Node with two children: get the in-order successor
        BSTNode<T>* temp = node->right;
        while (temp && temp->left != nullptr) {
            temp = temp->left;
        }

        // Copy the in-order successor's content to this node
        node->data = temp->data;

        // Delete the in-order successor
        node->right = removeNodeByID(node->right, temp->data.getId(), removed);
    }
    return node;
}






#endif
