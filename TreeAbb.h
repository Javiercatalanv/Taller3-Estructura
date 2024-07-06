#pragma once
#include "NodeAbb.h"

class TreeAbb {
private:
    NodeAbb* root;

    void insert(NodeAbb*& node, Product product);
    void inOrder(NodeAbb* node) const;

public:
    TreeAbb();

    void insert(Product product);
    void inOrder() const;
};

