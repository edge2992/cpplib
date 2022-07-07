---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graphTemplate.hpp
    title: graph/graphTemplate.hpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.hpp
    title: "Kruskal (\u6700\u5C0F\u5168\u57DF\u6728)"
  - icon: ':heavy_check_mark:'
    path: macros.hpp
    title: macros.hpp
  - icon: ':heavy_check_mark:'
    path: structure/unionFind.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_A
  bundledCode: "#line 1 \"test/graph/kruskal.aoj_ALDS1_12_A.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_A\"\n\n#include <iostream>\n\
    #line 2 \"graph/graphTemplate.hpp\"\n#include <vector>\n#line 4 \"graph/graphTemplate.hpp\"\
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
    \           std::end(ret));\n    return ret;\n  }\n};\n#line 4 \"graph/kruskal.hpp\"\
    \n\ntemplate <typename T>\nstruct MinimumSpaningTree {\n  T cost;\n  Edges<T>\
    \ edges;\n};\n\ntemplate <typename T>\nMinimumSpaningTree<T> kruskal(Edges<T>\
    \ &edges, int V) {\n  sort(begin(edges), end(edges),\n       [](const Edge<T>\
    \ &a, const Edge<T> &b) { return a.cost < b.cost; });\n  UnionFind uf(V);\n  T\
    \ total = T();\n  Edges<T> es;\n  for (auto &e : edges) {\n    if (uf.unite(e.from,\
    \ e.to)) {\n      es.emplace_back(e);\n      total += e.cost;\n    }\n  }\n  return\
    \ {total, es};\n}\n#line 2 \"macros.hpp\"\n#define rep(i, n) for (int i = 0; i\
    \ < (n); i++)\n#line 6 \"test/graph/kruskal.aoj_ALDS1_12_A.test.cpp\"\nusing namespace\
    \ std;\n\nint main() {\n  int N;\n  long long c;\n  cin >> N;\n  Edges<long long>\
    \ edges;\n  rep(i, N) {\n    rep(j, N) {\n      cin >> c;\n      if (c != -1)\
    \ edges.emplace_back(i, j, c);\n    }\n  }\n  MinimumSpaningTree<long long> mst\
    \ = kruskal(edges, N);\n  cout << mst.cost << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_12_A\"\n\
    \n#include <iostream>\n#include \"graph/kruskal.hpp\"\n#include \"macros.hpp\"\
    \nusing namespace std;\n\nint main() {\n  int N;\n  long long c;\n  cin >> N;\n\
    \  Edges<long long> edges;\n  rep(i, N) {\n    rep(j, N) {\n      cin >> c;\n\
    \      if (c != -1) edges.emplace_back(i, j, c);\n    }\n  }\n  MinimumSpaningTree<long\
    \ long> mst = kruskal(edges, N);\n  cout << mst.cost << endl;\n}"
  dependsOn:
  - graph/kruskal.hpp
  - graph/graphTemplate.hpp
  - structure/unionFind.hpp
  - macros.hpp
  isVerificationFile: true
  path: test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
  requiredBy: []
  timestamp: '2022-07-07 14:50:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
layout: document
redirect_from:
- /verify/test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
- /verify/test/graph/kruskal.aoj_ALDS1_12_A.test.cpp.html
title: test/graph/kruskal.aoj_ALDS1_12_A.test.cpp
---
