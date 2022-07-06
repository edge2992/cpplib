---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/comb.hpp
    title: math/comb.hpp
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
  bundledCode: "#line 1 \"math/mint.hpp\"\n\n\n#include<iostream>\nusing namespace\
    \ std;\nconst int mod = 1000000007;\n\nstruct mint {\n  long long x;\n  mint(long\
    \ long x = 0) : x((x % mod + mod) % mod) {}\n  mint operator-() const { return\
    \ mint(-x); }\n  mint& operator+=(const mint& a) {\n    if ((x += a.x) >= mod)\
    \ x -= mod;\n    return *this;\n  }\n  mint &operator-=(const mint& a) {\n   \
    \ if ((x += mod - a.x) >= mod) x -= mod;\n    return *this;\n  }\n  mint &operator*=(const\
    \ mint& a) {\n    (x *= a.x) %= mod;\n    return *this;\n  }\n  mint operator+(const\
    \ mint a){ return mint(*this) += a; }\n  mint operator-(const mint a){ return\
    \ mint(*this) -= a; }\n  mint operator*(const mint a){ return mint(*this) *= a;\
    \ }\n  mint pow(long long t) const {\n    if(!t) return 1;\n    mint a = pow(t>>1);\n\
    \    a *= a;\n    if(t&1) a *= *this;\n    return a;\n  }\n  mint inv() const\
    \ { return pow(mod-2);}\n  mint& operator/=(const mint& a) { return *this *= a.inv();\
    \ }\n  mint operator/(const mint& a){ return mint(*this) /= a; }\n};\nmint pow(mint\
    \ a, long long b){\n    return a.pow(b);\n}\nistream& operator>>(istream& is,\
    \ mint& a) { return is >> a.x; }\nostream& operator<<(ostream& os, const mint&\
    \ a) { return os << a.x; }\n\n"
  code: "#ifndef MODINT_HPP\n#define MODINT_HPP\n#include<iostream>\nusing namespace\
    \ std;\nconst int mod = 1000000007;\n\nstruct mint {\n  long long x;\n  mint(long\
    \ long x = 0) : x((x % mod + mod) % mod) {}\n  mint operator-() const { return\
    \ mint(-x); }\n  mint& operator+=(const mint& a) {\n    if ((x += a.x) >= mod)\
    \ x -= mod;\n    return *this;\n  }\n  mint &operator-=(const mint& a) {\n   \
    \ if ((x += mod - a.x) >= mod) x -= mod;\n    return *this;\n  }\n  mint &operator*=(const\
    \ mint& a) {\n    (x *= a.x) %= mod;\n    return *this;\n  }\n  mint operator+(const\
    \ mint a){ return mint(*this) += a; }\n  mint operator-(const mint a){ return\
    \ mint(*this) -= a; }\n  mint operator*(const mint a){ return mint(*this) *= a;\
    \ }\n  mint pow(long long t) const {\n    if(!t) return 1;\n    mint a = pow(t>>1);\n\
    \    a *= a;\n    if(t&1) a *= *this;\n    return a;\n  }\n  mint inv() const\
    \ { return pow(mod-2);}\n  mint& operator/=(const mint& a) { return *this *= a.inv();\
    \ }\n  mint operator/(const mint& a){ return mint(*this) /= a; }\n};\nmint pow(mint\
    \ a, long long b){\n    return a.pow(b);\n}\nistream& operator>>(istream& is,\
    \ mint& a) { return is >> a.x; }\nostream& operator<<(ostream& os, const mint&\
    \ a) { return os << a.x; }\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: math/mint.hpp
  requiredBy:
  - math/comb.hpp
  timestamp: '2022-07-06 10:14:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/modint_pow.aoj_DPL_5_A.test.cpp
  - test/comb.aoj_DPL_5_E.test.cpp
documentation_of: math/mint.hpp
layout: document
redirect_from:
- /library/math/mint.hpp
- /library/math/mint.hpp.html
title: math/mint.hpp
---
