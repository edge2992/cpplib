---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp
    title: test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"segmentTree/rangeMin.hpp\"\n#include<vector>\n#include<algorithm>\n\
    using namespace std;\nclass rangeMin {\n public:\n  int size_ = 1;\n  vector<long\
    \ long> dat;\n\n  void init(int sz) {\n    while (size_ <= sz) size_ *= 2;\n \
    \   dat.resize(size_ * 2, 1LL << 60);\n  }\n  void update(int pos, long long x)\
    \ {\n    pos += size_;\n    dat[pos] = x;\n    while (pos /= 2) {\n      dat[pos]\
    \ = min(dat[pos * 2], dat[pos * 2 + 1]);\n    }\n  }\n  long long query_(int l,\
    \ int r, int a, int b, int u) {\n    if (l <= a && b <= r) return dat[u];\n  \
    \  if (r <= a || b <= l) return 1LL << 60;\n    int mid = (a + b) / 2;\n    long\
    \ long v1 = query_(l, r, a, mid, u * 2);\n    long long v2 = query_(l, r, mid,\
    \ b, u * 2 + 1);\n    return min(v1, v2);\n  }\n  long long query(int l, int r)\
    \ { return query_(l, r, 0, size_, 1); }\n};\n"
  code: "#pragma once\n#include<vector>\n#include<algorithm>\nusing namespace std;\n\
    class rangeMin {\n public:\n  int size_ = 1;\n  vector<long long> dat;\n\n  void\
    \ init(int sz) {\n    while (size_ <= sz) size_ *= 2;\n    dat.resize(size_ *\
    \ 2, 1LL << 60);\n  }\n  void update(int pos, long long x) {\n    pos += size_;\n\
    \    dat[pos] = x;\n    while (pos /= 2) {\n      dat[pos] = min(dat[pos * 2],\
    \ dat[pos * 2 + 1]);\n    }\n  }\n  long long query_(int l, int r, int a, int\
    \ b, int u) {\n    if (l <= a && b <= r) return dat[u];\n    if (r <= a || b <=\
    \ l) return 1LL << 60;\n    int mid = (a + b) / 2;\n    long long v1 = query_(l,\
    \ r, a, mid, u * 2);\n    long long v2 = query_(l, r, mid, b, u * 2 + 1);\n  \
    \  return min(v1, v2);\n  }\n  long long query(int l, int r) { return query_(l,\
    \ r, 0, size_, 1); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: segmentTree/rangeMin.hpp
  requiredBy: []
  timestamp: '2022-07-06 23:37:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/segmentTree/rangeMin.aoj_DSL_2_A.test.cpp
documentation_of: segmentTree/rangeMin.hpp
layout: document
title: Range Minimum Query
---

- 半開半閉区間でクエリを処理することにすると扱いやすい
- 1-indexで木を構築すると実装しやすい
- クエリは0-index
