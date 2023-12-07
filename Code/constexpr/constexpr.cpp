//
// Created by weichuandong on 2023/12/5.
//
#include "iostream"

int main() {
    constexpr int num = 1 + 2 + 3;
    int nums[num] = {1, 2, 3};
    for (const auto &i: nums) {
        std::cout << i << " ";
    }
}
