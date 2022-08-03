#pragma once
#include <vector>


template <typename T>
struct BIT {
    int N;
    std::vector<T> bit;
    BIT(size_t sz) : N(sz + 2), bit(N, 0) {}

    void add(int i, T x){
        for(int idx = i; idx <= N; idx += idx & -idx){
            bit[idx] += x;
        }
    }

    T sum(int i){
        T ret = 0;
        for(int idx = i; idx > 0; idx -= idx & -idx){
            ret += bit[idx];
        }
        return ret;
    }
};