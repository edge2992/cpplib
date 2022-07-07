---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/comb.aoj_DPL_5_E.test.cpp
    title: test/comb.aoj_DPL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/comb.hpp\"\n#include <iostream>\n#include <vector>\n\
    #line 3 \"math/mint.hpp\"\nusing namespace std;\nconst int mod = 1000000007;\n\
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
    \ }\n#line 5 \"math/comb.hpp\"\nusing namespace std;\n\nstruct combination {\n\
    \  vector<mint> fact, ifact;\n  combination(int n) : fact(n + 1), ifact(n + 1)\
    \ {\n    fact[0] = 1;\n    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1]\
    \ * i;\n    ifact[n] = fact[n].inv();\n    for (int i = n; i >= 1; --i) ifact[i\
    \ - 1] = ifact[i] * i;\n  }\n  mint operator()(int n, int k) {\n    if (k < 0\
    \ || k > n) return 0;\n    return fact[n] * ifact[k] * ifact[n - k];\n  }\n};\n"
  code: "#pragma once\n#include <iostream>\n#include <vector>\n#include \"./mint.hpp\"\
    \nusing namespace std;\n\nstruct combination {\n  vector<mint> fact, ifact;\n\
    \  combination(int n) : fact(n + 1), ifact(n + 1) {\n    fact[0] = 1;\n    for\
    \ (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;\n    ifact[n] = fact[n].inv();\n\
    \    for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;\n  }\n  mint operator()(int\
    \ n, int k) {\n    if (k < 0 || k > n) return 0;\n    return fact[n] * ifact[k]\
    \ * ifact[n - k];\n  }\n};"
  dependsOn:
  - math/mint.hpp
  isVerificationFile: false
  path: math/comb.hpp
  requiredBy: []
  timestamp: '2022-07-06 23:37:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/comb.aoj_DPL_5_E.test.cpp
documentation_of: math/comb.hpp
layout: document
title: "combination mod \u7D44\u307F\u5408\u308F\u305B"
---

