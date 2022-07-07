---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal (\u6700\u5C0F\u5168\u57DF\u6728)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
    title: test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/union_find.aoj.test.cpp
    title: test/union_find.aoj.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/unionFind.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\nstruct UnionFind {\n  std::vector<int> data;\n  UnionFind() = default;\n\
    \n  explicit UnionFind(size_t sz) : data(sz, -1) {}\n\n  bool unite(int a, int\
    \ b) {\n    a = find(a);\n    b = find(b);\n    if (a == b) return false;\n  \
    \  if (data[a] < data[b]) std::swap(a, b);\n    data[a] += data[b];\n    data[b]\
    \ = a;\n    return true;\n  }\n\n  int find(int a) {\n    if (data[a] < 0) return\
    \ a;\n    return data[a] = find(data[a]);\n  }\n\n  int same(int a, int b) { return\
    \ find(a) == find(b); }\n\n  int size(int k) { return -data[find(k)]; }\n\n  std::vector<std::vector<int>>\
    \ groups() {\n    int n = (int)data.size();\n    std::vector<std::vector<int>>\
    \ ret(n);\n    for (int i = 0; i < n; i++) {\n      ret[find(i)].emplace_back(i);\n\
    \    }\n    ret.erase(std::remove_if(std::begin(ret), std::end(ret),\n       \
    \                 [&](const std::vector<int>& v) { return v.empty(); }),\n   \
    \           std::end(ret));\n    return ret;\n  }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nstruct UnionFind\
    \ {\n  std::vector<int> data;\n  UnionFind() = default;\n\n  explicit UnionFind(size_t\
    \ sz) : data(sz, -1) {}\n\n  bool unite(int a, int b) {\n    a = find(a);\n  \
    \  b = find(b);\n    if (a == b) return false;\n    if (data[a] < data[b]) std::swap(a,\
    \ b);\n    data[a] += data[b];\n    data[b] = a;\n    return true;\n  }\n\n  int\
    \ find(int a) {\n    if (data[a] < 0) return a;\n    return data[a] = find(data[a]);\n\
    \  }\n\n  int same(int a, int b) { return find(a) == find(b); }\n\n  int size(int\
    \ k) { return -data[find(k)]; }\n\n  std::vector<std::vector<int>> groups() {\n\
    \    int n = (int)data.size();\n    std::vector<std::vector<int>> ret(n);\n  \
    \  for (int i = 0; i < n; i++) {\n      ret[find(i)].emplace_back(i);\n    }\n\
    \    ret.erase(std::remove_if(std::begin(ret), std::end(ret),\n              \
    \          [&](const std::vector<int>& v) { return v.empty(); }),\n          \
    \    std::end(ret));\n    return ret;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/unionFind.hpp
  requiredBy:
  - graph/kruskal.hpp
  timestamp: '2022-07-06 23:37:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/union_find.aoj.test.cpp
  - test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
documentation_of: structure/unionFind.hpp
layout: document
title: Union Find
---

## UnionFind

- 集合を効率よく扱うためのライブラリ
- 集合の合併、どの集合に属しているかを調べることができる。
- 有向グラフの場合 SCC を使うことを検討する。

## 実装ヒント

- ルートの data には集合サイズの-1、ルート以外の data にはその集合のルートが入る(最終的に）
- unite はもともとルートだった場所の data しか変更しないので, find でルートをたどりながら、data の更新を行う。
- groups はそれぞれの集合のベクトルを返す.
