#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A"

#include <iostream>
#include "../math/mint.hpp"

int main() {
    int n, k; std::cin >> n >> k;
    std::cout << pow(mint(k), (long long)n) << std::endl;
    return 0;
}
