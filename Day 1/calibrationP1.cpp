#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
    int sum = 0;
    std::string in;
    while (!f.eof()) {
        f >> in;
        int first = -1;
        int second;
        int place = 1;
        for (int i = 0; i < in.size(); i++) {
            if ((in[i] >= 48 && in[i] <= 57)) {
                if (first == -1) first = in[i]-48;
                second = in[i]-48;
            }
        }
        
        sum += first * 10 + second;
    }
    std::cout << sum << std::endl;
}
