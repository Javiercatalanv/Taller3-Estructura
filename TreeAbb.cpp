#include <iostream>
#include "TreeAbb.h"
#include "NodeAbb.h"
using namespace std;

/*
TreeAbb::TreeAbb() : root(nullptr) {}

void TreeAbb::insert(Product product) {
    insert(root, product);
}

void TreeAbb::insert(NodeAbb*& node, Product product) {
    if (node == nullptr) {
        node = new NodeAbb(product);
    } else if (product.id < node->product.id) {
        insert(node->left, product);
    } else {
        insert(node->right, product);
    }
}

void TreeAbb::inOrder() const {
    inOrder(root);
}

void TreeAbb::inOrder(NodeAbb* node) const {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->product.id << " " << node->product.name << std::endl;
        inOrder(node->right);
    }
}
*/
