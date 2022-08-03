#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <iostream>
#include "structure/BIT.hpp"

int main(){
    int N, Q;
    std::cin >> N >> Q;
    BIT<long long> bt(N);
    for(int i=0; i<Q; i++){
        int com, x, y;
        std::cin >> com >> x >> y;
        if(com == 0){
            bt.add(x, y);
        }else{
            std::cout << bt.sum(y) - bt.sum(x-1) << std::endl;
        }
    }
}