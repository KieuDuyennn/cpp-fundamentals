#ifndef INTEGER_H
#define INTEGER_H

#include "../Object.h"

class Integer : public Object {
private:
    int _value;
public:
    Integer();
    Integer(int value);
    int value();
    std::string toString() override;
};

#endif // INTEGER_H
