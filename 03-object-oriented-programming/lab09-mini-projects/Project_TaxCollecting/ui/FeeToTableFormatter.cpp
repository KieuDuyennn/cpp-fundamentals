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
    builder << "Bao cao thu tien thue mat bang cho Ben Thanh\nThang: 05/2024\n\n";
    // Header uses the same widths as the rows: first cell padded, then "| " + cell for the rest.
    std::string header;
    for (size_t i = 0; i < _headers.size(); i++) {
        std::string cell = _headers[i];
        if (i + 1 < _headers.size() && (int)cell.size() < _columnSizes[i])
            cell += std::string(_columnSizes[i] - cell.size(), ' ');
        header += (i == 0 ? "" : "| ") + cell;
    }
    builder << header << "\n" << std::string(header.size() + 4, '-') << "\n";

    FeeToRowConverter rowConverter(_columnSizes);
    for (const auto& booth : booths) {
        builder << rowConverter.convert(booth) << "\n";
    }

    // Calculate total rent
    int totalRent = 0;
    for (const auto& booth : booths) {
        totalRent += booth->calculateTotalRent();
    }

    Integer totalRentObj(totalRent);
    IntToCurrencyConverter currencyConverter;
    builder << "\nTong tien thue mat bang thu trong thang: " << currencyConverter.convert(&totalRentObj) << "\n";

    return builder.str();
}

std::string FeeToTableFormatter::toString() {
    return "FeeToTableFormatter";
}
