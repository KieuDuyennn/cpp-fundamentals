#include "ParserFactory.h"
#include "../business/CircleParser.h"
#include "../business/RectangleParser.h"
#include "../business/SquareParser.h"

ParserFactory::ParserFactory() {
    _parsers["Circle"] = new CircleParser();
    _parsers["Rectangle"] = new RectangleParser();
    _parsers["Square"] = new SquareParser();
}

ParserFactory::~ParserFactory() {
    for (auto& pair : _parsers) {
        delete pair.second;
    }
}

IParsable* ParserFactory::create(const std::string& type) const {
    auto it = _parsers.find(type);
    return (it != _parsers.end()) ? it->second : nullptr;
}
