#include <iostream>
#include "NodeAvl.h"
#include "Product.h"

using namespace std;


NodeAvl :: NodeAvl (Product* trans) : transactions(trans),left(nullptr),right(nullptr),height(1){}