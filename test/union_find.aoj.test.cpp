#define PROBLEM \
  "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"
#include <iostream>

#include "../macros.hpp"
#include "../structure/unionFind.hpp"
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  rep(i, q) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      uf.unite(x, y);
    } else if (com == 1) {
      cout << uf.same(x, y) << endl;
    }
  }
  return 0;
}