#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_A"

#include <iostream>

#include "graph/minimumSpanningTree.hpp"
#include "macros.hpp"
using namespace std;

int main() {
  int N;
  long long c;
  cin >> N;
  Edges<long long> edges;
  rep(i, N) {
    rep(j, N) {
      cin >> c;
      if (c != -1) edges.emplace_back(i, j, c);
    }
  }
  MinimumSpanningTree<long long> mst = kruskal(edges, N);
  cout << mst.cost << endl;
}