#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
    int idSum = 0;
    int gameID = 0;
    std::string gameInfoRaw;
    std::string color;
    int count;
    while (getline(f, gameInfoRaw)) {
        gameID++;
        idSum += gameID;
        sstream gameInfo(gameInfoRaw);
        while (gameInfo >> count) {
            gameInfo >> color;
            if ((color == "red" && count >  12) || (color == "green" && count > 13) || (color == "blue" && count > 14)) {
                idSum -= gameID;
                std::cout << gameInfoRaw << std::endl;
                break;
            }
        }
    }
    std::cout << idSum << std::endl;
}
