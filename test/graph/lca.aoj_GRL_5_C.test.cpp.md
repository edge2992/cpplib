---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lca.hpp
    title: LCA (Lowerst Common Ancestor)
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
  bundledCode: "#line 1 \"test/graph/lca.aoj_GRL_5_C.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\n\n#include<iostream>\n\
    #line 1 \"graph/lca.hpp\"\n\n\n#include<vector>\nusing namespace std;\nusing Graph\
    \ = vector<vector<int>>;\n\nstruct LCA{\n  vector<vector<int>> parent;\n  vector<int>\
    \ dist;\n  LCA(const Graph &G, int root=0){ init(G, root);}\n\n  void init(const\
    \ Graph &G, int root=0){\n    int V = G.size();\n    int K = 1;\n    while((1<<K)\
    \ < V) K++;\n    parent.assign(K, vector<int>(V, -1));\n    dist.assign(V, -1);\n\
    \    dfs(G, root, -1, 0);\n    for(int k=0; k+1<K;k++){\n      for(int v = 0;\
    \ v<V;v++){\n        if(parent[k][v] < 0){\n          parent[k+1][v] = -1;\n \
    \       }else{\n          parent[k+1][v] = parent[k][parent[k][v]];\n        }\n\
    \      }\n    }\n  }\n\n  // \u6839\u304B\u3089\u306E\u8DDD\u96E2\u3068\u3072\u3068\
    \u3064\u5148\u306E\u9802\u70B9\u3092\u6C42\u3081\u308B\n  void dfs(const Graph\
    \ &G, int v, int p, int d){\n    parent[0][v] = p;\n    dist[v] = d;\n    for(auto\
    \ nx : G[v]){\n      if(nx != p) dfs(G, nx, v, d+1);\n    }\n  }\n\n  int query(int\
    \ u, int v){\n    if(dist[u] < dist[v]) swap(u, v);\n    int K = parent.size();\n\
    \    for(int k=0; k<K;k++){\n      if((dist[u] - dist[v]) >> k & 1){\n       \
    \ u = parent[k][u];\n      }\n    }\n    if(u == v) return u;\n    for(int k=K-1;k>=0;\
    \ k--){\n      if(parent[k][u] != parent[k][v]){\n        u = parent[k][u];\n\
    \        v = parent[k][v];\n      }\n    }\n    return parent[0][u];\n  }\n\n\
    \  int get_dist(int u, int v){\n    int p = query(u, v);\n    return dist[u] +\
    \ dist[v] - 2 * dist[p];\n  }\n};\n\n#line 2 \"macros.hpp\"\n#define rep(i, n)\
    \ for (int i = 0; i < (n); i++)\n#line 6 \"test/graph/lca.aoj_GRL_5_C.test.cpp\"\
    \n\nint main(){\n    int N, Q;\n    cin >> N;\n    Graph G(N);\n    rep(i, N){\n\
    \        int K, c;\n        cin >> K;\n        rep(j, K){\n            cin >>\
    \ c;\n            G[i].push_back(c);\n            G[c].push_back(i);\n       \
    \ }\n    }\n    LCA lca(G);\n    cin >> Q;\n    rep(i, Q){\n        int u, v;\n\
    \        cin >> u >> v;\n        cout << lca.query(u, v) << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C\"\
    \n\n#include<iostream>\n#include \"../../graph/lca.hpp\"\n#include \"../../macros.hpp\"\
    \n\nint main(){\n    int N, Q;\n    cin >> N;\n    Graph G(N);\n    rep(i, N){\n\
    \        int K, c;\n        cin >> K;\n        rep(j, K){\n            cin >>\
    \ c;\n            G[i].push_back(c);\n            G[c].push_back(i);\n       \
    \ }\n    }\n    LCA lca(G);\n    cin >> Q;\n    rep(i, Q){\n        int u, v;\n\
    \        cin >> u >> v;\n        cout << lca.query(u, v) << endl;\n    }\n}"
  dependsOn:
  - graph/lca.hpp
  - macros.hpp
  isVerificationFile: true
  path: test/graph/lca.aoj_GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2022-07-06 11:46:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/lca.aoj_GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/graph/lca.aoj_GRL_5_C.test.cpp
- /verify/test/graph/lca.aoj_GRL_5_C.test.cpp.html
title: test/graph/lca.aoj_GRL_5_C.test.cpp
---
