#pragma once
#include "IParsable.h"

class RectangleParser : public IParsable {
public:
    IShape* parse(const std::string& data) const override;
};
