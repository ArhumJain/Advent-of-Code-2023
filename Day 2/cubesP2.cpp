#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
    int idPowerSum = 0;
    std::string gameInfoRaw;
    std::string color;
    int count;
    while (getline(f, gameInfoRaw)) {
        int colorCounts[3] = {0,0,0};
        sstream gameInfo(gameInfoRaw);
        while (gameInfo >> count) {
            gameInfo >> color;
            if (color == "red") colorCounts[0] = max(colorCounts[0], count);
            else if (color == "green") colorCounts[1] = max(colorCounts[1], count);
            else if (color == "blue") colorCounts[2] = max(colorCounts[2], count);
        }
        idPowerSum += colorCounts[0] * colorCounts[1] * colorCounts[2];
    }
    std::cout << idPowerSum << std::endl;
}
