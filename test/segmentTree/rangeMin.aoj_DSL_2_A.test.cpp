#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../../segmentTree/rangeMin.hpp"
#include <iostream>

int main() {
  int n, q, com, x, y;
  cin >> n >> q;
  rangeMin st;
  st.init(n);
  for (int i = 0; i < n; i++) {
    st.update(i, INT32_MAX);
  }
  for (int i = 0; i < q; i++) {
    cin >> com >> x >> y;
    if (com == 0) {
      st.update(x, y);
    } else {
      cout << st.query(x, y + 1) << endl;
    }
  }
}