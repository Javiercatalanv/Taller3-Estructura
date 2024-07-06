#pragma once
#include "Product.h"

using namespace std;


class NodeAvl{
public:
    Product* transactions;
    NodeAvl* left;
    NodeAvl* right;
    int height;
    NodeAvl(Product* transaction);

};