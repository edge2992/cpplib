---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/structure/BIT.aoj_DSL_2_B.test.cpp
    title: test/structure/BIT.aoj_DSL_2_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"structure/BIT.hpp\"\n#include <vector>\n\n\ntemplate <typename\
    \ T>\nstruct BIT {\n    int N;\n    std::vector<T> bit;\n    BIT(size_t sz) :\
    \ N(sz + 2), bit(N, 0) {}\n\n    void add(int i, T x){\n        for(int idx =\
    \ i; idx <= N; idx += idx & -idx){\n            bit[idx] += x;\n        }\n  \
    \  }\n\n    T sum(int i){\n        T ret = 0;\n        for(int idx = i; idx >\
    \ 0; idx -= idx & -idx){\n            ret += bit[idx];\n        }\n        return\
    \ ret;\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n\n\ntemplate <typename T>\nstruct BIT {\n\
    \    int N;\n    std::vector<T> bit;\n    BIT(size_t sz) : N(sz + 2), bit(N, 0)\
    \ {}\n\n    void add(int i, T x){\n        for(int idx = i; idx <= N; idx += idx\
    \ & -idx){\n            bit[idx] += x;\n        }\n    }\n\n    T sum(int i){\n\
    \        T ret = 0;\n        for(int idx = i; idx > 0; idx -= idx & -idx){\n \
    \           ret += bit[idx];\n        }\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/BIT.hpp
  requiredBy: []
  timestamp: '2022-08-03 17:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/BIT.aoj_DSL_2_B.test.cpp
documentation_of: structure/BIT.hpp
layout: document
redirect_from:
- /library/structure/BIT.hpp
- /library/structure/BIT.hpp.html
title: structure/BIT.hpp
---
