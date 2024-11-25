#include "PostPrinter.h"
#include <iostream>

void PostPrinter::printPost(const GraphPost& post) {
    std::cout << post.toString();
}
