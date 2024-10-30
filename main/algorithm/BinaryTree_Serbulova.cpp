#include "sort_algorithms.h"
#include <iostream>
#include <list>

template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
TreeNode<T>* insert(TreeNode<T>* node, T value) {
    if (node == nullptr) {
        return new TreeNode<T>(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    }
    else {
        node->right = insert(node->right, value);
    }
    return node;
}

template<typename T>
void inorderTraversal(TreeNode<T>* node, std::list<T>& lst) {
    if (node != nullptr) {
        inorderTraversal(node->left, lst);
        lst.push_back(node->data);
        inorderTraversal(node->right, lst);
    }
}

void BinaryTree_Serbulova(std::list<int>& inputList) {
    TreeNode<int>* root = nullptr;

    for (const int& value : inputList) {
        root = insert(root, value);
    }

    std::list<int> sortedList;
    inorderTraversal(root, sortedList);

    inputList = sortedList;
}