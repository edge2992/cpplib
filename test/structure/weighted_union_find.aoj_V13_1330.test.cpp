#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"

#include <iostream>

#include "macros.hpp"
#include "structure/weightedUnionFind.hpp"

using namespace std;

int main() {
  int N, M;
  while (true) {
    cin >> N >> M;
    if (N == 0 && M == 0) break;
    UnionFind<int> uf(N);
    int l, r, w;
    char q;
    rep(i, M) {
      cin >> q;
      if (q == '!') {
        cin >> l >> r >> w;
        l--, r--;
        uf.merge(l, r, w);
      } else if (q == '?') {
        cin >> l >> r;
        l--, r--;
        if (uf.issame(l, r)) {
          cout << uf.diff(l, r) << endl;
        } else {
          cout << "UNKNOWN" << endl;
        }
      }
    }
  }
}