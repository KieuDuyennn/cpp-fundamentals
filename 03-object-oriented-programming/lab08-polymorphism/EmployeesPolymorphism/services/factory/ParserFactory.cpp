#include "ParserFactory.h"
#include <stdexcept>

ParserFactory::~ParserFactory() {
    for (auto& pair : _container) {
        delete pair.second;
    }
}

void ParserFactory::registerWith(IParsable* parser) {
    _container[parser->parsedObjectName()] = parser;
}

IParsable* ParserFactory::create(const std::string& type) const {
    auto it = _container.find(type);
    if (it == _container.end()) {
        throw std::runtime_error("No parser registered for type " + type);
    }
    return it->second;
}
