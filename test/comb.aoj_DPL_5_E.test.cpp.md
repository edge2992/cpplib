---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/comb.hpp
    title: math/comb.hpp
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: math/mint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E
  bundledCode: "#line 1 \"test/comb.aoj_DPL_5_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E\"\
    \n\n#include <iostream>\n#line 1 \"math/comb.hpp\"\n\n\n#line 4 \"math/comb.hpp\"\
    \n#include <vector>\n#line 1 \"math/mint.hpp\"\n\n\n#line 4 \"math/mint.hpp\"\n\
    using namespace std;\nconst int mod = 1000000007;\n\nstruct mint {\n  long long\
    \ x;\n  mint(long long x = 0) : x((x % mod + mod) % mod) {}\n  mint operator-()\
    \ const { return mint(-x); }\n  mint& operator+=(const mint& a) {\n    if ((x\
    \ += a.x) >= mod) x -= mod;\n    return *this;\n  }\n  mint &operator-=(const\
    \ mint& a) {\n    if ((x += mod - a.x) >= mod) x -= mod;\n    return *this;\n\
    \  }\n  mint &operator*=(const mint& a) {\n    (x *= a.x) %= mod;\n    return\
    \ *this;\n  }\n  mint operator+(const mint a){ return mint(*this) += a; }\n  mint\
    \ operator-(const mint a){ return mint(*this) -= a; }\n  mint operator*(const\
    \ mint a){ return mint(*this) *= a; }\n  mint pow(long long t) const {\n    if(!t)\
    \ return 1;\n    mint a = pow(t>>1);\n    a *= a;\n    if(t&1) a *= *this;\n \
    \   return a;\n  }\n  mint inv() const { return pow(mod-2);}\n  mint& operator/=(const\
    \ mint& a) { return *this *= a.inv(); }\n  mint operator/(const mint& a){ return\
    \ mint(*this) /= a; }\n};\nmint pow(mint a, long long b){\n    return a.pow(b);\n\
    }\nistream& operator>>(istream& is, mint& a) { return is >> a.x; }\nostream& operator<<(ostream&\
    \ os, const mint& a) { return os << a.x; }\n\n#line 6 \"math/comb.hpp\"\nusing\
    \ namespace std;\n\nstruct combination {\n  vector<mint> fact, ifact;\n  combination(int\
    \ n) : fact(n + 1), ifact(n + 1) {\n    fact[0] = 1;\n    for (int i = 1; i <=\
    \ n; ++i) fact[i] = fact[i - 1] * i;\n    ifact[n] = fact[n].inv();\n    for (int\
    \ i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;\n  }\n  mint operator()(int\
    \ n, int k) {\n    if (k < 0 || k > n) return 0;\n    return fact[n] * ifact[k]\
    \ * ifact[n - k];\n  }\n};\n\n#line 5 \"test/comb.aoj_DPL_5_E.test.cpp\"\n\nint\
    \ main() {\n    int n, k; std::cin >> n >> k;\n    combination comb(1009);\n \
    \   std::cout << comb(k, n) << std::endl;\n}\n\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E\"\
    \n\n#include <iostream>\n#include \"../math/comb.hpp\"\n\nint main() {\n    int\
    \ n, k; std::cin >> n >> k;\n    combination comb(1009);\n    std::cout << comb(k,\
    \ n) << std::endl;\n}\n\n"
  dependsOn:
  - math/comb.hpp
  - math/mint.hpp
  isVerificationFile: true
  path: test/comb.aoj_DPL_5_E.test.cpp
  requiredBy: []
  timestamp: '2022-07-06 10:15:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/comb.aoj_DPL_5_E.test.cpp
layout: document
redirect_from:
- /verify/test/comb.aoj_DPL_5_E.test.cpp
- /verify/test/comb.aoj_DPL_5_E.test.cpp.html
title: test/comb.aoj_DPL_5_E.test.cpp
---
