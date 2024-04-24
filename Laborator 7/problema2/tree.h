#pragma once

#include <iostream>
#include <queue>

template <typename T>
class TreeNode {
public:
    TreeNode(T val) : value(val), parent(nullptr), child(nullptr), frate(nullptr) {}

    T value;
    TreeNode* parent;
    TreeNode* child;
    TreeNode* frate;
};

template <typename T>
class Tree {
private:
    TreeNode<T>* root;

    void print_bfs(TreeNode<T>* node);
public:
    Tree() : root(nullptr) {}
    ~Tree() {
        delete_node(root);
    }

    void add_node(T val, TreeNode<T>* parent = nullptr) {
        TreeNode<T>* newNode = new TreeNode<T>(val);
        if (parent == nullptr) {
            root = newNode;
        }
        else {
            if (parent->child == nullptr) {
                parent->child = newNode;
            }
            else {
                TreeNode<T>* frate = parent->child;
                while (frate->frate != nullptr) {
                    frate = frate->frate;
                }
                frate->frate = newNode;
            }
            newNode->parent = parent;
        }
    }

    TreeNode<T>* get_node(TreeNode<T>* parent = nullptr) {
        return (parent == nullptr) ? root : parent->child;
    }

    void delete_node(TreeNode<T>* node) {
        if (node == nullptr)
            return;

        TreeNode<T>* child = node->child;
        while (child != nullptr) {
            TreeNode<T>* next = child->frate;
            delete_node(child);
            child = next;
        }
        delete node;
    }

    TreeNode<T>* find(TreeNode<T>* start, int val) {
        if (start == nullptr)
            return nullptr;

        if (start->value == val)
            return start;

        TreeNode<T>* found = nullptr;
        if (start->child != nullptr) {
            found = find(start->child, val);
        }
        if (found == nullptr && start->frate != nullptr) {
            found = find(start->frate, val);
        }
        return found;
    }

    void insert(T val, TreeNode<T>* parent, int index) {
        if (parent == nullptr)
            return;

        TreeNode<T>* newNode = new TreeNode<T>(val);
        TreeNode<T>* child = parent->child;

        if (index == 0) {
            newNode->frate = child;
            parent->child = newNode;
        }
        else {
            for (int i = 0; i < index - 1 && child != nullptr; ++i) {
                child = child->frate;
            }
            if (child != nullptr) {
                newNode->frate = child->frate;
                child->frate = newNode;
            }
        }
        newNode->parent = parent;
    }

    void sort(TreeNode<T>* node) {
        if (node == nullptr)
            return;

        bool swapped = true;
        while (swapped) {
            swapped = false;
            TreeNode<T>* current = node->child;
            TreeNode<T>* prev = nullptr;

            while (current != nullptr && current->frate != nullptr) {
                if (current->value > current->frate->value) {
                    swapped = true;
                    if (prev == nullptr) {
                        node->child = current->frate;
                    }
                    else {
                        prev->frate = current->frate;
                    }
                    TreeNode<T>* next = current->frate->frate;
                    current->frate->frate = current;
                    current->frate = next;
                    if (prev == nullptr) {
                        prev = node->child;
                    }
                    else {
                        prev = prev->frate;
                    }
                }
                else {
                    prev = current;
                    current = current->frate;
                }
            }
        }
    }

    int count(TreeNode<T>* node = nullptr) {
        if (node == nullptr)
            return 0;

        int cnt = 0;
        TreeNode<T>* current = node->child;
        while (current != nullptr) {
            cnt++;
            cnt += count(current);
            current = current->frate;
        }
        return cnt;
    }

    void print();


};

template<typename T>
void Tree<T>::print() {
    print_bfs(root);
}

template<typename T>
void Tree<T>::print_bfs(TreeNode<T>* node) {
    if (node == nullptr)
        return;

    std::queue<TreeNode<T>*> q;
    q.push(node);

    while (!q.empty()) {
        TreeNode<T>* current = q.front();
        q.pop();
        std::cout << current->value << " ";

        if (current->child != nullptr) {
            TreeNode<T>* child = current->child;
            while (child != nullptr) {
                q.push(child);
                child = child->frate;
            }
        }
    }
}

