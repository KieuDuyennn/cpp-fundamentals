#include <iostream>
#include <algorithm>

struct Interval {
    int start, end;
};

int main() {
    int n, P1, P2, P3, T1, T2;
    std::cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;

    Interval intervals[100];
    for (int i = 0; i < n; ++i) {
        std::cin >> intervals[i].start >> intervals[i].end;
    }

    int totalPower = 0;
    for (int i = 0; i < n; ++i) {
        totalPower += (intervals[i].end - intervals[i].start) * P1;

        if (i < n - 1) {
            int idleTime = intervals[i + 1].start - intervals[i].end;
            if (idleTime <= T1) {
                totalPower += idleTime * P1;
            } else if (idleTime <= T1 + T2) {
                totalPower += T1 * P1 + (idleTime - T1) * P2;
            } else {
                totalPower += T1 * P1 + T2 * P2 + (idleTime - T1 - T2) * P3;
            }
        }
    }

    std::cout << totalPower << std::endl;

    return 0;
}
