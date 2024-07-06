#include <iostream>
#include "NodeAvl.h"
#include "TreeAvl.h"
using namespace std;

 TreeAvl :: TreeAvl():root(nullptr){}

int TreeAvl::height(NodeAvl* n){
    if(n == nullptr) {return 0;}
    return n->height;
 }

int TreeAvl::max(int a,int b){
    if(a>b) {return a;}
    else {return b;}
}

NodeAvl* TreeAvl::rightRotate(NodeAvl* y){
    NodeAvl* x = y->left;
    NodeAvl* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left),height(y->right)+1);
    x->height = max(height(x->left),height(x->right)+1);
    return x;
}

NodeAvl* TreeAvl::leftRotate(NodeAvl* x){
    NodeAvl* y = x->right;
    NodeAvl* t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left),height(x->right)+1);
    y->height = max(height(y->left),height(y->right)+1);
    return y;
}

int TreeAvl::getBalance(NodeAvl* n)
{
    if(n == nullptr) {return 0;}
    return height(n->left)-height(n->right);
}

NodeAvl* TreeAvl::insertNode(NodeAvl* node, Product* transaction)
{
    if(node == nullptr) {return new NodeAvl(transaction);}
    if(transaction->getId() < node->transactions->getId()) {node->left = insertNode(node->left,transaction);}
    else if (transaction->getId() > node->transactions->getId()){node->right = insertNode(node->right,transaction);}
    else {return node;}
    node->height = 1+max(height(node->left),height(node->right));
    
    int balance = getBalance(node);
    if(balance > 1 && transaction->getId() < node->left->transactions->getId()) {return rightRotate(node);}
    if(balance < -1 && transaction->getId() > node->right->transactions->getId()) {return leftRotate(node);}
    if(balance > 1 && transaction->getId() > node->left->transactions->getId()) {node->left = leftRotate(node->left); return rightRotate(node);}
    if(balance < -1 && transaction->getId() < node->right->transactions->getId()) {node->right = rightRotate(node->right); return leftRotate(node);}
    return node;
}

Product* TreeAvl:: searchNode(NodeAvl* root, int key)
{
    if (root == nullptr) {return nullptr;}
    if(root->transactions->getId() == key){return root->transactions;}
    if(key < root->transactions->getId()){return searchNode(root->left,key);}
    return searchNode(root->right,key);
}

void TreeAvl::inOrder(NodeAvl* root){
    if(root!= nullptr)
    {
        inOrder(root->left);
        cout<< root->transactions->getId()<<" ";
        inOrder(root->right);
    }
}

void TreeAvl::insert(Product* transaction){
    root= insertNode(root,transaction);
}
Product* TreeAvl:: search (int key){
    return searchNode(root, key);
}

void TreeAvl:: displayInOrder(){
    inOrder(root);
}