---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/structure/weighted_union_find.aoj_V13_1330.test.cpp
    title: test/structure/weighted_union_find.aoj_V13_1330.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/weightedUnionFind.hpp\"\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate <typename T = int>\nstruct UnionFind {\n  vector<int>\
    \ par;\n  vector<int> rank;\n  vector<T> diff_weight;\n\n  UnionFind(int n = 1,\
    \ T SUM_UNITY = 0) { init(n, SUM_UNITY); }\n\n  void init(int n = 1, T SUM_UNITY\
    \ = 0) {\n    par.resize(n);\n    rank.resize(n);\n    diff_weight.resize(n);\n\
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
    \ = w;\n    return true;\n  }\n};\n"
  code: "#pragma once\n#include <vector>\nusing namespace std;\n\ntemplate <typename\
    \ T = int>\nstruct UnionFind {\n  vector<int> par;\n  vector<int> rank;\n  vector<T>\
    \ diff_weight;\n\n  UnionFind(int n = 1, T SUM_UNITY = 0) { init(n, SUM_UNITY);\
    \ }\n\n  void init(int n = 1, T SUM_UNITY = 0) {\n    par.resize(n);\n    rank.resize(n);\n\
    \    diff_weight.resize(n);\n    for (int i = 0; i < n; i++) {\n      par[i] =\
    \ i;\n      rank[i] = 0;\n      diff_weight[i] = SUM_UNITY;\n    }\n  }\n\n  int\
    \ root(int x) {\n    if (par[x] == x) {\n      return x;\n    } else {\n     \
    \ int r = root(par[x]);\n      diff_weight[x] += diff_weight[par[x]];\n      return\
    \ par[x] = r;\n    }\n  }\n\n  T weight(int x) {\n    root(x);\n    return diff_weight[x];\n\
    \  }\n\n  T diff(int x, int y) { return weight(y) - weight(x); }\n\n  bool issame(int\
    \ x, int y) { return root(x) == root(y); }\n\n  bool merge(int x, int y, T w)\
    \ {\n    w += weight(x);\n    w -= weight(y);\n\n    x = root(x);\n    y = root(y);\n\
    \    if (x == y) return false;\n    if (rank[x] < rank[y]) {\n      swap(x, y);\n\
    \      w = -w;\n    }\n    if (rank[x] == rank[y]) rank[x]++;\n    par[y] = x;\n\
    \    diff_weight[y] = w;\n    return true;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/weightedUnionFind.hpp
  requiredBy: []
  timestamp: '2022-12-04 10:55:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/weighted_union_find.aoj_V13_1330.test.cpp
documentation_of: structure/weightedUnionFind.hpp
layout: document
title: Weighted Union Find
---


## Weighted Union Find

- 重み付き Union Find
- weight(y) - weight(x) = w となるようにマージする

## 参考

- [重み付き Union-Find 木とそれが使える問題のまとめ、および、牛ゲーについて](https://qiita.com/drken/items/cce6fc5c579051e64fab)
