#pragma once
#include "IParsable.h"

class CircleParser : public IParsable {
public:
    IShape* parse(const std::string& data) const override;
};
