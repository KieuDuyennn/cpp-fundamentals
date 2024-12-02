#pragma once
#include "IParsable.h"

class SquareParser : public IParsable {
public:
    IShape* parse(const std::string& data) const override;
};
