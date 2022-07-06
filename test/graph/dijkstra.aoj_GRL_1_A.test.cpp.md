---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.hpp
    title: "Dijkstra (\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF)"
  - icon: ':heavy_check_mark:'
    path: graph/graphTemplate.hpp
    title: graph/graphTemplate.hpp
  - icon: ':heavy_check_mark:'
    path: macros.hpp
    title: macros.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/graph/dijkstra.aoj_GRL_1_A.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\n\n#include\
    \ <iostream>\n#include <limits>\n#line 1 \"graph/dijkstra.hpp\"\n\n\n#line 4 \"\
    graph/dijkstra.hpp\"\n#include <queue>\n#include <vector>\n#include <algorithm>\n\
    \n#line 1 \"graph/graphTemplate.hpp\"\n\n\n#line 4 \"graph/graphTemplate.hpp\"\
    \nusing namespace std;\n\ntemplate <typename T = int>\nstruct Edge {\n  int from,\
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
    \ &k) const {\n    return g[k];\n  }\n};\n\n\n#line 9 \"graph/dijkstra.hpp\"\n\
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
    };\n\n#line 2 \"macros.hpp\"\n#define rep(i, n) for (int i = 0; i < (n); i++)\n\
    #line 7 \"test/graph/dijkstra.aoj_GRL_1_A.test.cpp\"\nusing namespace std;\n\n\
    int main(){\n    long long N, E, R;\n    cin >> N >> E >> R;\n    Graph<long long>\
    \ G(N);\n    G.read(E, 0, true, true);\n    ShortestPath<long long> sp = dikstra(G,\
    \ R);\n    const long long INF = numeric_limits<long long>::max();\n    rep(i,\
    \ N){\n        if (sp.dist[i] == INF) {\n            cout << \"INF\" << endl;\n\
    \        } else {\n            cout << sp.dist[i] << endl;\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include <iostream>\n#include <limits>\n#include \"graph/dijkstra.hpp\"\n\
    #include \"macros.hpp\"\nusing namespace std;\n\nint main(){\n    long long N,\
    \ E, R;\n    cin >> N >> E >> R;\n    Graph<long long> G(N);\n    G.read(E, 0,\
    \ true, true);\n    ShortestPath<long long> sp = dikstra(G, R);\n    const long\
    \ long INF = numeric_limits<long long>::max();\n    rep(i, N){\n        if (sp.dist[i]\
    \ == INF) {\n            cout << \"INF\" << endl;\n        } else {\n        \
    \    cout << sp.dist[i] << endl;\n        }\n    }\n}"
  dependsOn:
  - graph/dijkstra.hpp
  - graph/graphTemplate.hpp
  - macros.hpp
  isVerificationFile: true
  path: test/graph/dijkstra.aoj_GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2022-07-06 17:28:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/dijkstra.aoj_GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/graph/dijkstra.aoj_GRL_1_A.test.cpp
- /verify/test/graph/dijkstra.aoj_GRL_1_A.test.cpp.html
title: test/graph/dijkstra.aoj_GRL_1_A.test.cpp
---
