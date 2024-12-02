#ifndef OBJECT_H
#define OBJECT_H

#include <string>

class Object {
public:
    virtual ~Object() = default;
    virtual std::string toString() const = 0;
};

#endif // OBJECT_H
