#pragma once
#include "../business/IParsable.h"
#include <map>
#include <string>

class ParserFactory {
private:
    std::map<std::string, IParsable*> _parsers;

public:
    ParserFactory();
    ~ParserFactory();
    IParsable* create(const std::string& type) const;
};
