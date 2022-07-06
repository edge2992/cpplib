---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mint.hpp
    title: mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A
  bundledCode: "#line 1 \"test/modint_pow.aoj_DPL_5_A.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A\"\n\n#include\
    \ <iostream>\n#line 1 \"math/mint.hpp\"\n\n\n#line 4 \"math/mint.hpp\"\nusing\
    \ namespace std;\nconst int mod = 1000000007;\n\nstruct mint {\n  long long x;\n\
    \  mint(long long x = 0) : x((x % mod + mod) % mod) {}\n  mint operator-() const\
    \ { return mint(-x); }\n  mint& operator+=(const mint& a) {\n    if ((x += a.x)\
    \ >= mod) x -= mod;\n    return *this;\n  }\n  mint &operator-=(const mint& a)\
    \ {\n    if ((x += mod - a.x) >= mod) x -= mod;\n    return *this;\n  }\n  mint\
    \ &operator*=(const mint& a) {\n    (x *= a.x) %= mod;\n    return *this;\n  }\n\
    \  mint operator+(const mint a){ return mint(*this) += a; }\n  mint operator-(const\
    \ mint a){ return mint(*this) -= a; }\n  mint operator*(const mint a){ return\
    \ mint(*this) *= a; }\n  mint pow(long long t) const {\n    if(!t) return 1;\n\
    \    mint a = pow(t>>1);\n    a *= a;\n    if(t&1) a *= *this;\n    return a;\n\
    \  }\n  mint inv() const { return pow(mod-2);}\n  mint& operator/=(const mint&\
    \ a) { return *this *= a.inv(); }\n  mint operator/(const mint& a){ return mint(*this)\
    \ /= a; }\n};\nmint pow(mint a, long long b){\n    return a.pow(b);\n}\nistream&\
    \ operator>>(istream& is, mint& a) { return is >> a.x; }\nostream& operator<<(ostream&\
    \ os, const mint& a) { return os << a.x; }\n\n#line 5 \"test/modint_pow.aoj_DPL_5_A.test.cpp\"\
    \n\nint main() {\n    int n, k; std::cin >> n >> k;\n    std::cout << pow(mint(k),\
    \ (long long)n) << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_A\"\
    \n\n#include <iostream>\n#include \"../math/mint.hpp\"\n\nint main() {\n    int\
    \ n, k; std::cin >> n >> k;\n    std::cout << pow(mint(k), (long long)n) << std::endl;\n\
    \    return 0;\n}\n"
  dependsOn:
  - math/mint.hpp
  isVerificationFile: true
  path: test/modint_pow.aoj_DPL_5_A.test.cpp
  requiredBy: []
  timestamp: '2022-07-06 10:14:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/modint_pow.aoj_DPL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/modint_pow.aoj_DPL_5_A.test.cpp
- /verify/test/modint_pow.aoj_DPL_5_A.test.cpp.html
title: test/modint_pow.aoj_DPL_5_A.test.cpp
---
