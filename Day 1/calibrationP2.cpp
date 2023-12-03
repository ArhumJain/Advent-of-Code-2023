#include "../utils/advent.h"

using namespace aoc;

constexpr int TEST = 0;
F f(TEST == 1 ? "test.in" : "main.in");

int main() {
    int sum = 0;
    std::string in;
    vec<std::string> number = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (!f.eof()) {
        f >> in;
        int first = -1;
        int second;
        int place = 1;
        int currNumber = -1; 
        for (int i=0; i<in.size(); i++) {
            if (in[i] >= 48 && in[i] <= 57) {
                currNumber = in[i]-48;
            } else {
                std::string s = "";
                for (int j=i; j<min(i+5, (int) in.size()); j++) {
                    s += in[j];
                    for (int k=0; k<9; k++) {
                        if (number[k] == s) {
                            j = in.size()+1;
                            currNumber = k+1;
                            break;
                        }
                    }
                }
            }
            if (first == -1 && currNumber != -1) first = currNumber;
            second = currNumber;
        }
        sum += first * 10 + second;
    }
    std::cout << sum << std::endl;
}