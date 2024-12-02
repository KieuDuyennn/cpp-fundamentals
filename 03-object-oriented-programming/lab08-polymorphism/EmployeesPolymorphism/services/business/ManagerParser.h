#ifndef MANAGERPARSER_H
#define MANAGERPARSER_H

#include "IParsable.h"
#include "../../models/Manager.h"

class ManagerParser : public IParsable {
public:
    Employee* parse(const std::string& data) const override;
    std::string parsedObjectName() const override { return "Manager"; }
};

#endif // MANAGERPARSER_H
