---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "Dijkstra (\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: SCC (Sstrongly Connected Components)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/graph/dijkstra.aoj_GRL_1_A.test.cpp
    title: test/graph/dijkstra.aoj_GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/graph/scc.aoj_GRL_3_C.test.cpp
    title: test/graph/scc.aoj_GRL_3_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graphTemplate.hpp\"\n\n\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate <typename T = int>\nstruct Edge {\n  int from, to;\n\
    \  T cost;\n  int idx;\n  Edge() = default;\n\n  Edge(int from, int to, T cost\
    \ = 1, int idx = -1)\n      : from(from), to(to), cost(cost), idx(idx) {}\n  operator\
    \ int() const { return to; }\n};\n\ntemplate <typename T = int>\nstruct Graph\
    \ {\n  vector<vector<Edge<T>>> g;\n  int es;\n\n  Graph() = default;\n  explicit\
    \ Graph(int n) : g(n), es(0) {}\n\n  size_t size() const { return g.size(); }\n\
    \n  void add_directed_edge(int from, int to, T cost = 1) {\n    g[from].emplace_back(from,\
    \ to, cost, es++);\n  }\n\n  void add_edge(int from, int to, T cost = 1) {\n \
    \   g[from].emplace_back(from, to, cost, es);\n    g[to].emplace_back(to, from,\
    \ cost, es++);\n  }\n  void read(int M, int padding = -1, bool weighted = false,\n\
    \            bool directed = false) {\n    for (int i = 0; i < M; i++) {\n   \
    \   int a, b;\n      cin >> a >> b;\n      a += padding;\n      b += padding;\n\
    \      T c = T(1);\n      if (weighted) {\n        cin >> c;\n      }\n      if\
    \ (directed) {\n        add_directed_edge(a, b, c);\n      } else {\n        add_edge(a,\
    \ b, c);\n      }\n    }\n  }\n  inline vector<Edge<T>> &operator[](const int\
    \ &k) { return g[k]; }\n\n  inline const vector<Edge<T>> &operator[](const int\
    \ &k) const {\n    return g[k];\n  }\n};\n\n\n"
  code: "#ifndef GRAPH_TEMPLATE_HPP\n#define GRAPH_TEMPLATE_HPP\n#include <vector>\n\
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
    \ &k) const {\n    return g[k];\n  }\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: graph/graphTemplate.hpp
  requiredBy:
  - graph/dijkstra.hpp
  - graph/scc.hpp
  timestamp: '2022-07-06 17:28:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/graph/scc.aoj_GRL_3_C.test.cpp
  - test/graph/dijkstra.aoj_GRL_1_A.test.cpp
documentation_of: graph/graphTemplate.hpp
layout: document
redirect_from:
- /library/graph/graphTemplate.hpp
- /library/graph/graphTemplate.hpp.html
title: graph/graphTemplate.hpp
---
