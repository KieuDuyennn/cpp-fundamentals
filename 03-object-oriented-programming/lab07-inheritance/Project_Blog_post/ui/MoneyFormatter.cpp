#include "MoneyFormatter.h"

std::string MoneyFormatter::formatMoney(int amount) {
    std::string formatted = std::to_string(amount);
    
    int insertPosition = formatted.length() - 3;
    while (insertPosition > 0) {
        formatted.insert(insertPosition, ".");
        insertPosition -= 3;
    }

    return formatted;
}
