#pragma once
#include "NodeAvl.h"
using namespace std;


class TreeAvl
{
    private:
    NodeAvl* root;

    int height(NodeAvl* N);
    int max(int a, int b);
    NodeAvl* rightRotate(NodeAvl* y);
    NodeAvl* leftRotate(NodeAvl* x);
    int getBalance(NodeAvl* N);
    NodeAvl* insertNode(NodeAvl* node, Product* transaction);
    Product* searchNode(NodeAvl* root, int key);
    void inOrder(NodeAvl* root);

    public:
    TreeAvl();
    void insert(Product* transaction);
    Product* search(int key);
    void displayInOrder();
};