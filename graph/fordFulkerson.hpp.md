---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp
    title: test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/fordFulkerson.hpp\"\n#include <limits>\n#include <vector>\n\
    using namespace std;\n\ntemplate <typename T = int>\nstruct FordFulkerson {\n\
    \  struct Edge {\n    int to;\n    T cost;\n    int rev;\n  };\n\n public:\n \
    \ int size_ = 0;\n  vector<bool> used;\n  vector<vector<Edge>> G;\n\n  FordFulkerson(int\
    \ size) : size_(size), G(size), used(size) {}\n\n  void add_edge(int from, int\
    \ to, T cap) {\n    G[from].push_back({to, cap, (int)G[to].size()});\n    G[to].push_back({from,\
    \ 0, (int)G[from].size() - 1});\n  }\n\n  T max_flow(int s, int t) {\n    T total_flow\
    \ = 0;\n    while (true) {\n      fill(used.begin(), used.end(), false);\n   \
    \   T INF = numeric_limits<T>::max();\n      T F = dfs(s, t, INF);\n      if (F\
    \ == 0) break;\n      total_flow += F;\n    }\n    return total_flow;\n  }\n\n\
    \ private:\n  T dfs(int pos, int goal, T F) {\n    if (pos == goal) return F;\n\
    \    used[pos] = true;\n    for (int i = 0; i < G[pos].size(); i++) {\n      auto\
    \ &e = G[pos][i];\n      if (!used[e.to] && e.cost > 0) {\n        T d = dfs(e.to,\
    \ goal, min(F, e.cost));\n        if (d > 0) {\n          e.cost -= d;\n     \
    \     G[e.to][e.rev].cost += d;\n          return d;\n        }\n      }\n   \
    \ }\n    return 0;\n  }\n};\n"
  code: "#pragma once\n#include <limits>\n#include <vector>\nusing namespace std;\n\
    \ntemplate <typename T = int>\nstruct FordFulkerson {\n  struct Edge {\n    int\
    \ to;\n    T cost;\n    int rev;\n  };\n\n public:\n  int size_ = 0;\n  vector<bool>\
    \ used;\n  vector<vector<Edge>> G;\n\n  FordFulkerson(int size) : size_(size),\
    \ G(size), used(size) {}\n\n  void add_edge(int from, int to, T cap) {\n    G[from].push_back({to,\
    \ cap, (int)G[to].size()});\n    G[to].push_back({from, 0, (int)G[from].size()\
    \ - 1});\n  }\n\n  T max_flow(int s, int t) {\n    T total_flow = 0;\n    while\
    \ (true) {\n      fill(used.begin(), used.end(), false);\n      T INF = numeric_limits<T>::max();\n\
    \      T F = dfs(s, t, INF);\n      if (F == 0) break;\n      total_flow += F;\n\
    \    }\n    return total_flow;\n  }\n\n private:\n  T dfs(int pos, int goal, T\
    \ F) {\n    if (pos == goal) return F;\n    used[pos] = true;\n    for (int i\
    \ = 0; i < G[pos].size(); i++) {\n      auto &e = G[pos][i];\n      if (!used[e.to]\
    \ && e.cost > 0) {\n        T d = dfs(e.to, goal, min(F, e.cost));\n        if\
    \ (d > 0) {\n          e.cost -= d;\n          G[e.to][e.rev].cost += d;\n   \
    \       return d;\n        }\n      }\n    }\n    return 0;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/fordFulkerson.hpp
  requiredBy:
  - test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp
  timestamp: '2022-09-24 02:39:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/fordFulkerson.hpp
layout: document
title: Ford Fulkerson (maximum flow)
---

## 概要

- 最大フローを求めるアルゴリズム

## 実装のヒント

- 残余グラフを使う
- dfsで残余グラフを探索して、スタートからゴールまでのパスとそのコストの最小値を求める。 $O(E)$
- そのパスに流せるだけ(パスの最小コスト）流す。
- これを残余グラフのパスがなくなるまで繰り返す。繰り返しの回数は最大で再流量回$F$となる。
- 全体の計算量は$O(FE)$
