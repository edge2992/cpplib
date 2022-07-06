#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"

#include <iostream>
#include "graph/scc.hpp"
#include "graph/graphTemplate.hpp"
#include "macros.hpp"
using namespace std;

int main() {
  int V, E, Q;
  cin >> V >> E;
  Graph<int> G(V);
  G.read(E, 0, false, true);
  SCC<int> scc(G);
  cin >> Q;
  rep(i, Q) {
    int u, v;
    cin >> u >> v;
    cout << (scc.is_same(u, v) ? 1 : 0) << endl;
  }
}