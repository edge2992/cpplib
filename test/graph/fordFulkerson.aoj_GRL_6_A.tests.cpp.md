---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: graph/fordFulkerson.hpp
    title: Ford Fulkerson (maximum flow)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A
  bundledCode: "#line 1 \"test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp\"\n#define\
    \ PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n#line 2 \"graph/fordFulkerson.hpp\"\n#include <limits>\n#include <vector>\n\
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
    \ }\n    return 0;\n  }\n};\n#line 4 \"test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp\"\
    \n\n#include <iostream>\nusing namespace std;\n#define rep(i, n) for (int i =\
    \ 0; i < (int)(n); i++)\n#define Int long long\n\nint main() {\n  int V, E;\n\
    \  cin >> V >> E;\n  int u, v;\n  Int c;\n  FordFulkerson<Int> ff(V);\n  rep(i,\
    \ E) {\n    cin >> u >> v >> c;\n    ff.add_edge(u, v, c);\n  }\n  cout << ff.max_flow(0,\
    \ V - 1) << endl;\n}\n"
  code: "#define PROBLEM \\\n  \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A\"\
    \n#include \"graph/fordFulkerson.hpp\"\n\n#include <iostream>\nusing namespace\
    \ std;\n#define rep(i, n) for (int i = 0; i < (int)(n); i++)\n#define Int long\
    \ long\n\nint main() {\n  int V, E;\n  cin >> V >> E;\n  int u, v;\n  Int c;\n\
    \  FordFulkerson<Int> ff(V);\n  rep(i, E) {\n    cin >> u >> v >> c;\n    ff.add_edge(u,\
    \ v, c);\n  }\n  cout << ff.max_flow(0, V - 1) << endl;\n}"
  dependsOn:
  - graph/fordFulkerson.hpp
  isVerificationFile: false
  path: test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp
  requiredBy: []
  timestamp: '2022-09-24 02:39:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp
layout: document
redirect_from:
- /library/test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp
- /library/test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp.html
title: test/graph/fordFulkerson.aoj_GRL_6_A.tests.cpp
---
