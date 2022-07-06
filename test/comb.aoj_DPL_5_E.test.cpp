#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E"

#include <iostream>
#include "../math/comb.hpp"

int main() {
    int n, k; std::cin >> n >> k;
    combination comb(1009);
    std::cout << comb(k, n) << std::endl;
}

