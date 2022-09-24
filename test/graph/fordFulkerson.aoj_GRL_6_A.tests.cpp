#define PROBLEM \
  "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "graph/fordFulkerson.hpp"

#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Int long long

int main() {
  int V, E;
  cin >> V >> E;
  int u, v;
  Int c;
  FordFulkerson<Int> ff(V);
  rep(i, E) {
    cin >> u >> v >> c;
    ff.add_edge(u, v, c);
  }
  cout << ff.max_flow(0, V - 1) << endl;
}