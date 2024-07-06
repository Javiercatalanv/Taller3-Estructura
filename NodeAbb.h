#pragma once
#include "Product.h"
using namespace std;

class NodeAbb {
public:
    Product* transactions;
    NodeAbb* left;
    NodeAbb* right;
    NodeAbb(Product* transaction);
};

