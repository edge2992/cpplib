---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: macros.hpp
    title: macros.hpp
  - icon: ':heavy_check_mark:'
    path: structure/weightedUnionFind.hpp
    title: Weighted Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330
  bundledCode: "#line 1 \"test/structure/weighted_union_find.aoj_V13_1330.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \n\n#include <iostream>\n\n#line 2 \"macros.hpp\"\n#define rep(i, n) for (int\
    \ i = 0; i < (n); i++)\n#line 2 \"structure/weightedUnionFind.hpp\"\n#include\
    \ <vector>\nusing namespace std;\n\ntemplate <typename T = int>\nstruct UnionFind\
    \ {\n  vector<int> par;\n  vector<int> rank;\n  vector<T> diff_weight;\n\n  UnionFind(int\
    \ n = 1, T SUM_UNITY = 0) { init(n, SUM_UNITY); }\n\n  void init(int n = 1, T\
    \ SUM_UNITY = 0) {\n    par.resize(n);\n    rank.resize(n);\n    diff_weight.resize(n);\n\
    \    for (int i = 0; i < n; i++) {\n      par[i] = i;\n      rank[i] = 0;\n  \
    \    diff_weight[i] = SUM_UNITY;\n    }\n  }\n\n  int root(int x) {\n    if (par[x]\
    \ == x) {\n      return x;\n    } else {\n      int r = root(par[x]);\n      diff_weight[x]\
    \ += diff_weight[par[x]];\n      return par[x] = r;\n    }\n  }\n\n  T weight(int\
    \ x) {\n    root(x);\n    return diff_weight[x];\n  }\n\n  T diff(int x, int y)\
    \ { return weight(y) - weight(x); }\n\n  bool issame(int x, int y) { return root(x)\
    \ == root(y); }\n\n  bool merge(int x, int y, T w) {\n    w += weight(x);\n  \
    \  w -= weight(y);\n\n    x = root(x);\n    y = root(y);\n    if (x == y) return\
    \ false;\n    if (rank[x] < rank[y]) {\n      swap(x, y);\n      w = -w;\n   \
    \ }\n    if (rank[x] == rank[y]) rank[x]++;\n    par[y] = x;\n    diff_weight[y]\
    \ = w;\n    return true;\n  }\n};\n#line 7 \"test/structure/weighted_union_find.aoj_V13_1330.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n  int N, M;\n  while (true) {\n    cin\
    \ >> N >> M;\n    if (N == 0 && M == 0) break;\n    UnionFind<int> uf(N);\n  \
    \  int l, r, w;\n    char q;\n    rep(i, M) {\n      cin >> q;\n      if (q ==\
    \ '!') {\n        cin >> l >> r >> w;\n        l--, r--;\n        uf.merge(l,\
    \ r, w);\n      } else if (q == '?') {\n        cin >> l >> r;\n        l--, r--;\n\
    \        if (uf.issame(l, r)) {\n          cout << uf.diff(l, r) << endl;\n  \
    \      } else {\n          cout << \"UNKNOWN\" << endl;\n        }\n      }\n\
    \    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330\"\
    \n\n#include <iostream>\n\n#include \"macros.hpp\"\n#include \"structure/weightedUnionFind.hpp\"\
    \n\nusing namespace std;\n\nint main() {\n  int N, M;\n  while (true) {\n    cin\
    \ >> N >> M;\n    if (N == 0 && M == 0) break;\n    UnionFind<int> uf(N);\n  \
    \  int l, r, w;\n    char q;\n    rep(i, M) {\n      cin >> q;\n      if (q ==\
    \ '!') {\n        cin >> l >> r >> w;\n        l--, r--;\n        uf.merge(l,\
    \ r, w);\n      } else if (q == '?') {\n        cin >> l >> r;\n        l--, r--;\n\
    \        if (uf.issame(l, r)) {\n          cout << uf.diff(l, r) << endl;\n  \
    \      } else {\n          cout << \"UNKNOWN\" << endl;\n        }\n      }\n\
    \    }\n  }\n}"
  dependsOn:
  - macros.hpp
  - structure/weightedUnionFind.hpp
  isVerificationFile: true
  path: test/structure/weighted_union_find.aoj_V13_1330.test.cpp
  requiredBy: []
  timestamp: '2022-12-04 10:55:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/structure/weighted_union_find.aoj_V13_1330.test.cpp
layout: document
redirect_from:
- /verify/test/structure/weighted_union_find.aoj_V13_1330.test.cpp
- /verify/test/structure/weighted_union_find.aoj_V13_1330.test.cpp.html
title: test/structure/weighted_union_find.aoj_V13_1330.test.cpp
---
