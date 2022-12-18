---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphTemplate.hpp
    title: graph/graphTemplate.hpp
  - icon: ':heavy_check_mark:'
    path: structure/unionFind.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
    title: test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/graphTemplate.hpp\"\n#include <vector>\n#include <iostream>\n\
    using namespace std;\n\ntemplate <typename T = int>\nstruct Edge {\n  int from,\
    \ to;\n  T cost;\n  int idx;\n  Edge() = default;\n\n  Edge(int from, int to,\
    \ T cost = 1, int idx = -1)\n      : from(from), to(to), cost(cost), idx(idx)\
    \ {}\n  operator int() const { return to; }\n};\n\ntemplate <typename T = int>\n\
    struct Graph {\n  vector<vector<Edge<T>>> g;\n  int es;\n\n  Graph() = default;\n\
    \  explicit Graph(int n) : g(n), es(0) {}\n\n  size_t size() const { return g.size();\
    \ }\n\n  void add_directed_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from,\
    \ to, cost, es++);\n  }\n\n  void add_edge(int from, int to, T cost = 1) {\n \
    \   g[from].emplace_back(from, to, cost, es);\n    g[to].emplace_back(to, from,\
    \ cost, es++);\n  }\n  void read(int M, int padding = -1, bool weighted = false,\n\
    \            bool directed = false) {\n    for (int i = 0; i < M; i++) {\n   \
    \   int a, b;\n      cin >> a >> b;\n      a += padding;\n      b += padding;\n\
    \      T c = T(1);\n      if (weighted) {\n        cin >> c;\n      }\n      if\
    \ (directed) {\n        add_directed_edge(a, b, c);\n      } else {\n        add_edge(a,\
    \ b, c);\n      }\n    }\n  }\n  inline vector<Edge<T>> &operator[](const int\
    \ &k) { return g[k]; }\n\n  inline const vector<Edge<T>> &operator[](const int\
    \ &k) const { return g[k]; }\n};\n\ntemplate <typename T>\nusing Edges = vector<Edge<T>>;\n\
    #line 2 \"structure/unionFind.hpp\"\n#include <algorithm>\n#line 4 \"structure/unionFind.hpp\"\
    \n\nstruct UnionFind {\n  std::vector<int> data;\n  UnionFind() = default;\n\n\
    \  explicit UnionFind(size_t sz) : data(sz, -1) {}\n\n  bool unite(int a, int\
    \ b) {\n    a = find(a);\n    b = find(b);\n    if (a == b) return false;\n  \
    \  if (data[a] < data[b]) std::swap(a, b);\n    data[a] += data[b];\n    data[b]\
    \ = a;\n    return true;\n  }\n\n  int find(int a) {\n    if (data[a] < 0) return\
    \ a;\n    return data[a] = find(data[a]);\n  }\n\n  int same(int a, int b) { return\
    \ find(a) == find(b); }\n\n  int size(int k) { return -data[find(k)]; }\n\n  std::vector<std::vector<int>>\
    \ groups() {\n    int n = (int)data.size();\n    std::vector<std::vector<int>>\
    \ ret(n);\n    for (int i = 0; i < n; i++) {\n      ret[find(i)].emplace_back(i);\n\
    \    }\n    ret.erase(std::remove_if(std::begin(ret), std::end(ret),\n       \
    \                 [&](const std::vector<int>& v) { return v.empty(); }),\n   \
    \           std::end(ret));\n    return ret;\n  }\n};\n#line 4 \"graph/minimumSpanningTree.hpp\"\
    \n\ntemplate <typename T>\nstruct MinimumSpanningTree {\n  T cost;\n  Edges<T>\
    \ edges;\n};\n\ntemplate <typename T>\nMinimumSpanningTree<T> kruskal(Edges<T>\
    \ &edges, int V) {\n  sort(begin(edges), end(edges),\n       [](const Edge<T>\
    \ &a, const Edge<T> &b) { return a.cost < b.cost; });\n  UnionFind uf(V);\n  T\
    \ total = T();\n  Edges<T> es;\n  for (auto &e : edges) {\n    if (uf.unite(e.from,\
    \ e.to)) {\n      es.emplace_back(e);\n      total += e.cost;\n    }\n  }\n  return\
    \ {total, es};\n}\n"
  code: "#pragma once\n#include \"graph/graphTemplate.hpp\"\n#include \"structure/unionFind.hpp\"\
    \n\ntemplate <typename T>\nstruct MinimumSpanningTree {\n  T cost;\n  Edges<T>\
    \ edges;\n};\n\ntemplate <typename T>\nMinimumSpanningTree<T> kruskal(Edges<T>\
    \ &edges, int V) {\n  sort(begin(edges), end(edges),\n       [](const Edge<T>\
    \ &a, const Edge<T> &b) { return a.cost < b.cost; });\n  UnionFind uf(V);\n  T\
    \ total = T();\n  Edges<T> es;\n  for (auto &e : edges) {\n    if (uf.unite(e.from,\
    \ e.to)) {\n      es.emplace_back(e);\n      total += e.cost;\n    }\n  }\n  return\
    \ {total, es};\n}"
  dependsOn:
  - graph/graphTemplate.hpp
  - structure/unionFind.hpp
  isVerificationFile: false
  path: graph/minimumSpanningTree.hpp
  requiredBy: []
  timestamp: '2022-12-17 23:55:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
documentation_of: graph/minimumSpanningTree.hpp
layout: document
redirect_from:
- /library/graph/minimumSpanningTree.hpp
- /library/graph/minimumSpanningTree.hpp.html
title: graph/minimumSpanningTree.hpp
---
