---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/union_find.aoj.test.cpp
    title: test/union_find.aoj.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/unionFind.md
    document_title: Union-Find
    links: []
  bundledCode: "#line 1 \"structure/unionFind.hpp\"\n\n\n#include <algorithm>\n#include\
    \ <vector>\n\n/**\n * @brief Union-Find\n * @docs docs/unionFind.md\n */\nstruct\
    \ UnionFind {\n  std::vector<int> data;\n  UnionFind() = default;\n\n  explicit\
    \ UnionFind(size_t sz) : data(sz, -1) {}\n\n  bool unite(int a, int b) {\n   \
    \ a = find(a);\n    b = find(b);\n    if (a == b) return false;\n    if (data[a]\
    \ < data[b]) std::swap(a, b);\n    data[a] += data[b];\n    data[b] = a;\n   \
    \ return true;\n  }\n\n  int find(int a) {\n    if (data[a] < 0) return a;\n \
    \   return data[a] = find(data[a]);\n  }\n\n  int same(int a, int b) { return\
    \ find(a) == find(b); }\n\n  int size(int k) { return -data[find(k)]; }\n\n  std::vector<std::vector<int>>\
    \ groups() {\n    int n = (int)data.size();\n    std::vector<std::vector<int>>\
    \ ret(n);\n    for (int i = 0; i < n; i++) {\n      ret[find(i)].emplace_back(i);\n\
    \    }\n    ret.erase(std::remove_if(std::begin(ret), std::end(ret),\n       \
    \                 [&](const std::vector<int>& v) { return v.empty(); }),\n   \
    \           std::end(ret));\n    return ret;\n  }\n};\n\n"
  code: "#ifndef UNION_FIND_HPP\n#define UNION_FIND_HPP\n#include <algorithm>\n#include\
    \ <vector>\n\n/**\n * @brief Union-Find\n * @docs docs/unionFind.md\n */\nstruct\
    \ UnionFind {\n  std::vector<int> data;\n  UnionFind() = default;\n\n  explicit\
    \ UnionFind(size_t sz) : data(sz, -1) {}\n\n  bool unite(int a, int b) {\n   \
    \ a = find(a);\n    b = find(b);\n    if (a == b) return false;\n    if (data[a]\
    \ < data[b]) std::swap(a, b);\n    data[a] += data[b];\n    data[b] = a;\n   \
    \ return true;\n  }\n\n  int find(int a) {\n    if (data[a] < 0) return a;\n \
    \   return data[a] = find(data[a]);\n  }\n\n  int same(int a, int b) { return\
    \ find(a) == find(b); }\n\n  int size(int k) { return -data[find(k)]; }\n\n  std::vector<std::vector<int>>\
    \ groups() {\n    int n = (int)data.size();\n    std::vector<std::vector<int>>\
    \ ret(n);\n    for (int i = 0; i < n; i++) {\n      ret[find(i)].emplace_back(i);\n\
    \    }\n    ret.erase(std::remove_if(std::begin(ret), std::end(ret),\n       \
    \                 [&](const std::vector<int>& v) { return v.empty(); }),\n   \
    \           std::end(ret));\n    return ret;\n  }\n};\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: structure/unionFind.hpp
  requiredBy: []
  timestamp: '2022-07-06 08:44:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/union_find.aoj.test.cpp
documentation_of: structure/unionFind.hpp
layout: document
redirect_from:
- /library/structure/unionFind.hpp
- /library/structure/unionFind.hpp.html
title: Union-Find
---
