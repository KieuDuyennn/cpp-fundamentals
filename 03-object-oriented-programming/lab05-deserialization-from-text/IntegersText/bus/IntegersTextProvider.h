#ifndef INTEGERSTEXTPROVIDER_H
#define INTEGERSTEXTPROVIDER_H

#include <vector>
#include <string>

class IntegersTextProvider {
public:
    std::vector<int> read(const std::string& filename);
};

#endif
