#include "MoneyFormatter.h"

std::string MoneyFormatter::format(int amount) {
    std::string num = std::to_string(amount);
    std::string result;
    int count = 0;

    // Duyệt chuỗi số từ phải sang trái và chèn dấu chấm sau mỗi 3 chữ số
    for (auto it = num.rbegin(); it != num.rend(); ++it) {
        result.insert(result.begin(), *it);
        if (++count % 3 == 0 && it + 1 != num.rend()) {
            result.insert(result.begin(), '.');
        }
    }
    return result;
}
