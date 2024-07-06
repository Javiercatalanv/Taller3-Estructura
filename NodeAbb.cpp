#include <iostream>
#include "NodeAbb.h"
#include "Product.h"

using namespace std;


NodeAbb :: NodeAbb (Product* trans) : transactions(trans),left(nullptr),right(nullptr){}