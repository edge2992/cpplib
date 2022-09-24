---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/comb.hpp
    title: "combination mod \u7D44\u307F\u5408\u308F\u305B"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/comb.aoj_DPL_5_E.test.cpp
    title: test/comb.aoj_DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/modint_pow.aoj_DPL_5_A.test.cpp
    title: test/modint_pow.aoj_DPL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/mint.hpp\"\n#include<iostream>\nusing namespace std;\n\
    const int mod = 1000000007;\n\nstruct mint {\n  long long x;\n  mint(long long\
    \ x = 0) : x((x % mod + mod) % mod) {}\n  mint operator-() const { return mint(-x);\
    \ }\n  mint& operator+=(const mint& a) {\n    if ((x += a.x) >= mod) x -= mod;\n\
    \    return *this;\n  }\n  mint &operator-=(const mint& a) {\n    if ((x += mod\
    \ - a.x) >= mod) x -= mod;\n    return *this;\n  }\n  mint &operator*=(const mint&\
    \ a) {\n    (x *= a.x) %= mod;\n    return *this;\n  }\n  mint operator+(const\
    \ mint a){ return mint(*this) += a; }\n  mint operator-(const mint a){ return\
    \ mint(*this) -= a; }\n  mint operator*(const mint a){ return mint(*this) *= a;\
    \ }\n  mint pow(long long t) const {\n    if(!t) return 1;\n    mint a = pow(t>>1);\n\
    \    a *= a;\n    if(t&1) a *= *this;\n    return a;\n  }\n  mint inv() const\
    \ { return pow(mod-2);}\n  mint& operator/=(const mint& a) { return *this *= a.inv();\
    \ }\n  mint operator/(const mint& a){ return mint(*this) /= a; }\n};\nmint pow(mint\
    \ a, long long b){\n    return a.pow(b);\n}\nistream& operator>>(istream& is,\
    \ mint& a) { return is >> a.x; }\nostream& operator<<(ostream& os, const mint&\
    \ a) { return os << a.x; }\n"
  code: "#pragma once\n#include<iostream>\nusing namespace std;\nconst int mod = 1000000007;\n\
    \nstruct mint {\n  long long x;\n  mint(long long x = 0) : x((x % mod + mod) %\
    \ mod) {}\n  mint operator-() const { return mint(-x); }\n  mint& operator+=(const\
    \ mint& a) {\n    if ((x += a.x) >= mod) x -= mod;\n    return *this;\n  }\n \
    \ mint &operator-=(const mint& a) {\n    if ((x += mod - a.x) >= mod) x -= mod;\n\
    \    return *this;\n  }\n  mint &operator*=(const mint& a) {\n    (x *= a.x) %=\
    \ mod;\n    return *this;\n  }\n  mint operator+(const mint a){ return mint(*this)\
    \ += a; }\n  mint operator-(const mint a){ return mint(*this) -= a; }\n  mint\
    \ operator*(const mint a){ return mint(*this) *= a; }\n  mint pow(long long t)\
    \ const {\n    if(!t) return 1;\n    mint a = pow(t>>1);\n    a *= a;\n    if(t&1)\
    \ a *= *this;\n    return a;\n  }\n  mint inv() const { return pow(mod-2);}\n\
    \  mint& operator/=(const mint& a) { return *this *= a.inv(); }\n  mint operator/(const\
    \ mint& a){ return mint(*this) /= a; }\n};\nmint pow(mint a, long long b){\n \
    \   return a.pow(b);\n}\nistream& operator>>(istream& is, mint& a) { return is\
    \ >> a.x; }\nostream& operator<<(ostream& os, const mint& a) { return os << a.x;\
    \ }"
  dependsOn: []
  isVerificationFile: false
  path: math/mint.hpp
  requiredBy:
  - math/comb.hpp
  timestamp: '2022-07-06 23:37:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/comb.aoj_DPL_5_E.test.cpp
  - test/modint_pow.aoj_DPL_5_A.test.cpp
documentation_of: math/mint.hpp
layout: document
title: mod int
---

## Mint

- 自動で mod を取る整数型
