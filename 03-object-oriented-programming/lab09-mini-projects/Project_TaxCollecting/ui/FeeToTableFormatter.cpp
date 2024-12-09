// // #include "FeeToTableFormatter.h"


// // FeeToTableFormatter::FeeToTableFormatter(std::vector<std::string> headers, std::vector<int> columnSizes) {
// //     _headers = headers;
// //     _columnSizes = columnSizes;
// // }

// // std::string FeeToTableFormatter::convert(Object* object) {
// //     auto booths = *dynamic_cast<std::vector<IBaseBooth*>*>(object);
// //     return formatTable(booths);
// // }

// // std::string FeeToTableFormatter::formatTable(const std::vector<IBaseBooth*>& booths) {
// //     std::stringstream builder;

// //     // Sort booths by total rent in ascending order
// //     std::vector<IBaseBooth*> sortedBooths = booths;
// //     std::sort(sortedBooths.begin(), sortedBooths.end())  ;

// //     builder << "Bao cao thu tien thue mat bang cho Ben Thanh\nThang: 05/2024\n\n";
// //     builder << "STT | Ma sap | Loai      | Dien tich | Tien / m2 | Tien mat bang | Phi khac  | Tong cong \n";
// //     builder << "-----------------------------------------------------------------------------------------\n";

// //     FeeToRowConverter rowConverter(_columnSizes);
// //     for (const auto& booth : sortedBooths) {
// //         builder << rowConverter.convert(booth) << "\n";
// //     }

// //     // Calculate total rent
// //     int totalRent = 0;
// //     for (const auto& booth : sortedBooths) {
// //         totalRent += booth->calculateTotalRent();
// //     }

// //     Integer totalRentObj(totalRent);
// //     IntToCurrencyConverter currencyConverter;
// //     builder << "\nTong tien thue mat bang thu trong thang: " << currencyConverter.convert(&totalRentObj) << " d\n";

// //     return builder.str();
// // }

// // std::string FeeToTableFormatter::toString() {
// //     return "FeeToTableFormatter";
// // }

// #include "FeeToTableFormatter.h"


// FeeToTableFormatter::FeeToTableFormatter(std::vector<std::string> headers, std::vector<int> columnSizes) {
//     _headers = headers;
//     _columnSizes = columnSizes;
// }

// std::string FeeToTableFormatter::convert(const std::vector<IBaseBooth*>& booths) {
//     return formatTable(booths);
// }

// std::string FeeToTableFormatter::formatTable(const std::vector<IBaseBooth*>& booths) {
//     std::stringstream builder;

//     // Sort booths by total rent in ascending order
//     std::vector<IBaseBooth*> sortedBooths = booths;
//     std::sort(sortedBooths.begin(), sortedBooths.end());  

//     builder << "Bao cao thu tien thue mat bang cho Ben Thanh\nThang: 05/2024\n\n";
//     builder << "STT | Ma sap | Loai      | Dien tich | Tien / m2 | Tien mat bang | Phi khac  | Tong cong \n";
//     builder << "-----------------------------------------------------------------------------------------\n";

//     FeeToRowConverter rowConverter(_columnSizes);
//     for (const auto& booth : sortedBooths) {
//         builder << rowConverter.convert(booth) << "\n";
//     }

//     // Calculate total rent
//     int totalRent = 0;
//     for (const auto& booth : sortedBooths) {
//         totalRent += booth->calculateTotalRent();
//     }

//     Integer totalRentObj(totalRent);
//     IntToCurrencyConverter currencyConverter;
//     builder << "\nTong tien thue mat bang thu trong thang: " << currencyConverter.convert(&totalRentObj) << " d\n";

//     return builder.str();
// }

// std::string FeeToTableFormatter::toString() {
//     return "FeeToTableFormatter";
// }

#include "FeeToTableFormatter.h"


FeeToTableFormatter::FeeToTableFormatter(std::vector<std::string> headers, std::vector<int> columnSizes) {
    _headers = headers;
    _columnSizes = columnSizes;
}

std::string FeeToTableFormatter::convert(const std::vector<IBaseBooth*>& booths) {
    return formatTable(booths);
}

std::string FeeToTableFormatter::formatTable(const std::vector<IBaseBooth*>& booths) {
    std::stringstream builder;

    // Sort booths by total rent in ascending order
    std::vector<IBaseBooth*> sortedBooths = booths;
    std::sort(sortedBooths.begin(), sortedBooths.end()); 

    builder << "Bao cao thu tien thue mat bang cho Ben Thanh\nThang: 05/2024\n\n";
    builder << "STT | Ma sap | Loai      | Dien tich | Tien / m2 | Tien mat bang | Phi khac  | Tong cong \n";
    builder << "-----------------------------------------------------------------------------------------\n";

    FeeToRowConverter rowConverter(_columnSizes);
    for (const auto& booth : sortedBooths) {
        builder << rowConverter.convert(booth) << "\n";
    }

    // Calculate total rent
    int totalRent = 0;
    for (const auto& booth : sortedBooths) {
        totalRent += booth->calculateTotalRent();
    }

    Integer totalRentObj(totalRent);
    IntToCurrencyConverter currencyConverter;
    builder << "\nTong tien thue mat bang thu trong thang: " << currencyConverter.convert(&totalRentObj) << " d\n";

    return builder.str();
}

std::string FeeToTableFormatter::toString() {
    return "FeeToTableFormatter";
}
