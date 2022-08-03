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
  bundledCode: "#line 2 \"structure/bit.hpp\"\n#include <vector>\n\n\ntemplate <typename\
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
  path: structure/bit.hpp
  requiredBy: []
  timestamp: '2022-08-03 17:09:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/structure/BIT.aoj_DSL_2_B.test.cpp
documentation_of: structure/bit.hpp
layout: document
title: BIT (Binary Indexed Tree)
---

## 概要

- 1-indexにして閉区間で考える

## 実装のヒント

- (ind & -ind) で最後の区間を求めて足し引きをする。
- 足し算は木の親をたどる。
- 引き算は深さ優先探索の帰りがけ順の前の区間に移動する。

## 参考

- [スライド](http://hos.ac/slides/20140319_bit.pdf)
- [かつっぱEDPC Q](https://www.youtube.com/watch?v=kEkvTR-guyg&t=603s)
