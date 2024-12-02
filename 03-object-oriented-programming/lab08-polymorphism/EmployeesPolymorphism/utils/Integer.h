#ifndef INTEGER_H
#define INTEGER_H

#include "../models/Object.h"

class Integer : public Object {
private:
    int _value;

public:
    Integer();
    Integer(int value);
    int value() const;
    std::string toString() const override;
};

#endif // INTEGER_H
