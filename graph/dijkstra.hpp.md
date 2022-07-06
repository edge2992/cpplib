---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphTemplate.hpp
    title: graph/graphTemplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.aoj_GRL_1_A.test.cpp
    title: test/graph/dijkstra.aoj_GRL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/dijkstra.hpp\"\n\n\n#include <limits>\n#include <queue>\n\
    #include <vector>\n#include <algorithm>\n\n#line 1 \"graph/graphTemplate.hpp\"\
    \n\n\n#line 4 \"graph/graphTemplate.hpp\"\nusing namespace std;\n\ntemplate <typename\
    \ T = int>\nstruct Edge {\n  int from, to;\n  T cost;\n  int idx;\n  Edge() =\
    \ default;\n\n  Edge(int from, int to, T cost = 1, int idx = -1)\n      : from(from),\
    \ to(to), cost(cost), idx(idx) {}\n  operator int() const { return to; }\n};\n\
    \ntemplate <typename T = int>\nstruct Graph {\n  vector<vector<Edge<T>>> g;\n\
    \  int es;\n\n  Graph() = default;\n  explicit Graph(int n) : g(n), es(0) {}\n\
    \n  size_t size() const { return g.size(); }\n\n  void add_directed_edge(int from,\
    \ int to, T cost = 1) {\n    g[from].emplace_back(from, to, cost, es++);\n  }\n\
    \n  void add_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from,\
    \ to, cost, es);\n    g[to].emplace_back(to, from, cost, es++);\n  }\n  void read(int\
    \ M, int padding = -1, bool weighted = false,\n            bool directed = false)\
    \ {\n    for (int i = 0; i < M; i++) {\n      int a, b;\n      cin >> a >> b;\n\
    \      a += padding;\n      b += padding;\n      T c = T(1);\n      if (weighted)\
    \ {\n        cin >> c;\n      }\n      if (directed) {\n        add_directed_edge(a,\
    \ b, c);\n      } else {\n        add_edge(a, b, c);\n      }\n    }\n  }\n  inline\
    \ vector<Edge<T>> &operator[](const int &k) { return g[k]; }\n\n  inline const\
    \ vector<Edge<T>> &operator[](const int &k) const {\n    return g[k];\n  }\n};\n\
    \n\n#line 9 \"graph/dijkstra.hpp\"\nusing namespace std;\n\ntemplate <typename\
    \ T = int>\nstruct ShortestPath {\n  vector<T> dist;\n  vector<int> from, id;\n\
    };\n\ntemplate <typename T>\nShortestPath<T> dikstra(const Graph<T> &g, int s)\
    \ {\n  ShortestPath<T> sp;\n  const auto INF = numeric_limits<T>::max();\n  sp.dist.resize(g.size(),\
    \ INF);\n  sp.dist[s] = 0;\n  sp.from.resize(g.size(), -1);\n  sp.id.resize(g.size(),\
    \ -1);\n  using Pi = pair<T, int>;\n  priority_queue<Pi, vector<Pi>, greater<>>\
    \ pq;\n  pq.emplace(0, s);\n  while (!pq.empty()) {\n    auto [cost, idx] = pq.top();\n\
    \    pq.pop();\n    if (sp.dist[idx] < cost) continue;\n    for (auto &e : g[idx])\
    \ {\n      auto next_cost = cost + e.cost;\n      if (sp.dist[e.to] <= next_cost)\
    \ continue;\n      sp.dist[e.to] = next_cost;\n      sp.from[e.to] = idx;\n  \
    \    sp.id[e.to] = e.idx;\n      pq.emplace(sp.dist[e.to], e.to);\n    }\n  }\n\
    \  return sp;\n};\n\n"
  code: "#ifndef DIJKSTRA_HPP\n#define DIJKSTRA_HPP\n#include <limits>\n#include <queue>\n\
    #include <vector>\n#include <algorithm>\n\n#include \"./graphTemplate.hpp\"\n\
    using namespace std;\n\ntemplate <typename T = int>\nstruct ShortestPath {\n \
    \ vector<T> dist;\n  vector<int> from, id;\n};\n\ntemplate <typename T>\nShortestPath<T>\
    \ dikstra(const Graph<T> &g, int s) {\n  ShortestPath<T> sp;\n  const auto INF\
    \ = numeric_limits<T>::max();\n  sp.dist.resize(g.size(), INF);\n  sp.dist[s]\
    \ = 0;\n  sp.from.resize(g.size(), -1);\n  sp.id.resize(g.size(), -1);\n  using\
    \ Pi = pair<T, int>;\n  priority_queue<Pi, vector<Pi>, greater<>> pq;\n  pq.emplace(0,\
    \ s);\n  while (!pq.empty()) {\n    auto [cost, idx] = pq.top();\n    pq.pop();\n\
    \    if (sp.dist[idx] < cost) continue;\n    for (auto &e : g[idx]) {\n      auto\
    \ next_cost = cost + e.cost;\n      if (sp.dist[e.to] <= next_cost) continue;\n\
    \      sp.dist[e.to] = next_cost;\n      sp.from[e.to] = idx;\n      sp.id[e.to]\
    \ = e.idx;\n      pq.emplace(sp.dist[e.to], e.to);\n    }\n  }\n  return sp;\n\
    };\n#endif"
  dependsOn:
  - graph/graphTemplate.hpp
  isVerificationFile: false
  path: graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2022-07-06 17:28:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/dijkstra.aoj_GRL_1_A.test.cpp
documentation_of: graph/dijkstra.hpp
layout: document
title: "Dijkstra (\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF)"
---

## 概要

- 負辺のないグラフで単一始点最短経路を求めるアルゴリズム
- ShortestPath の from にはその頂点に到達する直前の頂点が格納され、id には直前の辺の id が格納される。
- $O(E\log V)$

## 実装のヒント

- priority_que で距離が短い順に処理する
- すでに小さいコストで到達できる経路が確認できている場合はスキップする
- priority_que には、すでに短い距離で訪れている頂点を追加しないようにする

[](https://ei1333.github.io/library/graph/shortest-path/dijkstra.hpp)
