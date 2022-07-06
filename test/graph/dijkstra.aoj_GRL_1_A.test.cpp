#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"

#include <iostream>
#include <limits>
#include "graph/dijkstra.hpp"
#include "macros.hpp"
using namespace std;

int main(){
    long long N, E, R;
    cin >> N >> E >> R;
    Graph<long long> G(N);
    G.read(E, 0, true, true);
    ShortestPath<long long> sp = dijkstra(G, R);
    const long long INF = numeric_limits<long long>::max();
    rep(i, N){
        if (sp.dist[i] == INF) {
            cout << "INF" << endl;
        } else {
            cout << sp.dist[i] << endl;
        }
    }
}