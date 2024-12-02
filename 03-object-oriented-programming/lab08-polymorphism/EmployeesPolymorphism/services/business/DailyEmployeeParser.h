#ifndef DAILYEMPLOYEEPARSER_H
#define DAILYEMPLOYEEPARSER_H

#include "IParsable.h"
#include "../../models/DailyEmployee.h"

class DailyEmployeeParser : public IParsable {
public:
    Employee* parse(const std::string& data) const override;
    std::string parsedObjectName() const override { return "DailyEmployee"; }
};

#endif // DAILYEMPLOYEEPARSER_H
