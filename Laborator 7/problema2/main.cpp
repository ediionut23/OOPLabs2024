#include <iostream>
#include "tree.h"

int main() {
    Tree<int> tree;
    tree.add_node(5);
    auto root = tree.get_node();

    tree.add_node(10, root);
    tree.add_node(7, root);
    tree.add_node(15, root);
    tree.add_node(3, root->child);
    tree.add_node(12, root->child);
    tree.add_node(20, root->child);

    tree.add_node(30, root->child->child);
    tree.add_node(25, root->child->child);
    tree.add_node(1, root->child->child->child);
    tree.add_node(8, root->child->child->child->frate);

    std::cout << "Initial tree (BFS): ";
    tree.print();

    auto found = tree.find(root, 7);
    std::cout << std::endl;
    if (found)
        std::cout << "Found node with value 7\n";

    tree.insert(8, root, 1);
    std::cout << "Tree after insertion (BFS): ";
    tree.print();
    std::cout << std::endl;

    tree.sort(root);
    std::cout << "Tree after sorting (BFS): ";
    tree.print();
    std::cout << std::endl;
    std::cout << "Number of children of root: " << tree.count(root) << std::endl;

    tree.delete_node(root);

    return 0;
}
