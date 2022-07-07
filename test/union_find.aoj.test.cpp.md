---
data:
  _extendedDependsOn:
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A
  bundledCode: "#line 1 \"test/union_find.aoj.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A\"\n#include\
    \ <iostream>\n\n#line 2 \"macros.hpp\"\n#define rep(i, n) for (int i = 0; i <\
    \ (n); i++)\n#line 2 \"structure/unionFind.hpp\"\n#include <algorithm>\n#include\
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
    \           std::end(ret));\n    return ret;\n  }\n};\n#line 7 \"test/union_find.aoj.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  UnionFind\
    \ uf(n);\n  rep(i, q) {\n    int com, x, y;\n    cin >> com >> x >> y;\n    if\
    \ (com == 0) {\n      uf.unite(x, y);\n    } else if (com == 1) {\n      cout\
    \ << uf.same(x, y) << endl;\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A\"\
    \n#include <iostream>\n\n#include \"../macros.hpp\"\n#include \"../structure/unionFind.hpp\"\
    \nusing namespace std;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  UnionFind\
    \ uf(n);\n  rep(i, q) {\n    int com, x, y;\n    cin >> com >> x >> y;\n    if\
    \ (com == 0) {\n      uf.unite(x, y);\n    } else if (com == 1) {\n      cout\
    \ << uf.same(x, y) << endl;\n    }\n  }\n  return 0;\n}"
  dependsOn:
  - macros.hpp
  - structure/unionFind.hpp
  isVerificationFile: true
  path: test/union_find.aoj.test.cpp
  requiredBy: []
  timestamp: '2022-07-06 23:37:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/union_find.aoj.test.cpp
layout: document
redirect_from:
- /verify/test/union_find.aoj.test.cpp
- /verify/test/union_find.aoj.test.cpp.html
title: test/union_find.aoj.test.cpp
---
