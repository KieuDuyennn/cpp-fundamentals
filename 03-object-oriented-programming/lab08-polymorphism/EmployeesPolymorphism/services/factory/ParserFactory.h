#ifndef PARSERFACTORY_H
#define PARSERFACTORY_H

#include "../business/IParsable.h"
#include <map>
#include <string>

class ParserFactory {
private:
    std::map<std::string, IParsable*> _container;

public:
    ~ParserFactory();
    void registerWith(IParsable* parser);
    IParsable* create(const std::string& type) const;
};

#endif // PARSERFACTORY_H
