#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"

#include<iostream>
#include "../../graph/lca.hpp"
#include "../../macros.hpp"

int main(){
    int N, Q;
    cin >> N;
    Graph G(N);
    rep(i, N){
        int K, c;
        cin >> K;
        rep(j, K){
            cin >> c;
            G[i].push_back(c);
            G[c].push_back(i);
        }
    }
    LCA lca(G);
    cin >> Q;
    rep(i, Q){
        int u, v;
        cin >> u >> v;
        cout << lca.query(u, v) << endl;
    }
}