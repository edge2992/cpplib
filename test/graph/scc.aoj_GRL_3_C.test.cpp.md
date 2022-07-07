---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphTemplate.hpp
    title: graph/graphTemplate.hpp
  - icon: ':heavy_check_mark:'
    path: graph/scc.hpp
    title: SCC (Sstrongly Connected Components)
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C
  bundledCode: "#line 1 \"test/graph/scc.aoj_GRL_3_C.test.cpp\"\n#define PROBLEM \\\
    \n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\n\n\
    #include <iostream>\n#line 2 \"graph/scc.hpp\"\n#include <algorithm>\n#include\
    \ <unordered_map>\n#include <vector>\n\n#line 4 \"graph/graphTemplate.hpp\"\n\
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
    #line 7 \"graph/scc.hpp\"\nusing namespace std;\n\ntemplate <typename T = int>\n\
    struct SCC {\npublic:\n  int n;\n  Graph<T> G;\n  vector<int> component;\n  SCC(Graph<T>\
    \ &_G) {\n    n = _G.size();\n    G = _G;\n    build();\n  }\n\n  void build()\
    \ {\n    rG = Graph(n);\n    for(size_t i =0;i<n;i++){\n      for(auto &e: G[i])\
    \ {\n        rG.add_directed_edge(e.to, e.from, e.cost);\n      }\n    }\n   \
    \ component.assign(n, -1);\n    used.assign(n, false);\n    for (size_t v = 0;\
    \ v < n; v++)\n      if (!used[v]) dfs(v);\n    reverse(order.begin(), order.end());\n\
    \    int k = 0;\n    for (auto v : order)\n      if (component[v] == -1) rdfs(v,\
    \ k), k++;\n  }\n\n  bool is_same(int u, int v) { return component[u] == component[v];\
    \ }\n\n  long long count_pair() {\n    unordered_map<int, long long> value_counts;\n\
    \    for (int k : component) {\n      value_counts[k]++;\n    }\n    long long\
    \ ans = 0;\n    for (auto x : value_counts) {\n      ans += x.second * (x.second\
    \ - 1) / 2;\n    }\n    return ans;\n  }\n\nprivate:\n  Graph<T> rG;\n  vector<int>\
    \ order;\n  vector<bool> used;\n\n  void dfs(int v) {\n    used[v] = 1;\n    for\
    \ (auto nv : G[v]) {\n      if (!used[nv]) dfs(nv);\n    }\n    order.push_back(v);\n\
    \  }\n\n  void rdfs(int v, int k) {\n    component[v] = k;\n    for (auto nv :\
    \ rG[v]) {\n      if (component[nv] < 0) rdfs(nv, k);\n    }\n  }\n};\n#line 2\
    \ \"macros.hpp\"\n#define rep(i, n) for (int i = 0; i < (n); i++)\n#line 8 \"\
    test/graph/scc.aoj_GRL_3_C.test.cpp\"\nusing namespace std;\n\nint main() {\n\
    \  int V, E, Q;\n  cin >> V >> E;\n  Graph<int> G(V);\n  G.read(E, 0, false, true);\n\
    \  SCC<int> scc(G);\n  cin >> Q;\n  rep(i, Q) {\n    int u, v;\n    cin >> u >>\
    \ v;\n    cout << (scc.is_same(u, v) ? 1 : 0) << endl;\n  }\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C\"\
    \n\n#include <iostream>\n#include \"graph/scc.hpp\"\n#include \"graph/graphTemplate.hpp\"\
    \n#include \"macros.hpp\"\nusing namespace std;\n\nint main() {\n  int V, E, Q;\n\
    \  cin >> V >> E;\n  Graph<int> G(V);\n  G.read(E, 0, false, true);\n  SCC<int>\
    \ scc(G);\n  cin >> Q;\n  rep(i, Q) {\n    int u, v;\n    cin >> u >> v;\n   \
    \ cout << (scc.is_same(u, v) ? 1 : 0) << endl;\n  }\n}"
  dependsOn:
  - graph/scc.hpp
  - graph/graphTemplate.hpp
  - macros.hpp
  isVerificationFile: true
  path: test/graph/scc.aoj_GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2022-07-07 14:50:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/scc.aoj_GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/graph/scc.aoj_GRL_3_C.test.cpp
- /verify/test/graph/scc.aoj_GRL_3_C.test.cpp.html
title: test/graph/scc.aoj_GRL_3_C.test.cpp
---
