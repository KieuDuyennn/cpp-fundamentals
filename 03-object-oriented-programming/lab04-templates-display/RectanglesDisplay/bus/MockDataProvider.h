#ifndef MOCKDATAPROVIDER_H
#define MOCKDATAPROVIDER_H

#include <vector>
#include "../../lib/Rectangle.h"

class MockDataProvider {
public:
    std::vector<Rectangle> getAllRectangles();
};

#endif // MOCKDATAPROVIDER_H
