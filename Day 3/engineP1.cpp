#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

vec2d<int> directions = {{1,1}, {0,1}, {-1,1}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1,0}};
int main() {
    int sum = 0;
    vec2d<char> engine;
    std::string row = "";
    int rowID = 0;
    while (std::getline(f, row)) {
        engine.push_back(vec<char>());
        for (int i=0; i<row.size(); i++) {
            engine[rowID].push_back(row[i]);
        }
        rowID++;
    }
    bool numberFound = false;
    bool isPartNumber = false;
    int currNumber = 0;
    for (int i=0; i<engine.size(); i++) {
        for (int j=0; j<engine[0].size(); j++) {
            if (j == 0 || engine[i][j] < 48 || engine[i][j] > 57) {
                if (isPartNumber) sum += currNumber;
                isPartNumber = false;
                numberFound = false;
            }
            if (engine[i][j] >= 48 && engine[i][j] <= 57) {
                if (!numberFound) {
                    currNumber = atoi(&engine[i][j]);
                    numberFound = true;
                }
                if (!isPartNumber) {
                    for (auto dir: directions) {
                        if (i+dir[0] < 0 || i+dir[0] >= engine.size() || j+dir[1] < 0 || j+dir[1] >= engine[0].size()) continue;
                        if (engine[i+dir[0]][j+dir[1]] != 46 && (engine[i+dir[0]][j+dir[1]] < 48 || engine[i+dir[0]][j+dir[1]] > 57)) {
                            isPartNumber = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    std::cout << sum << std::endl;
}