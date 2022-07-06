#pragma once
#include<vector>
#include<algorithm>
using namespace std;
class rangeMin {
 public:
  int size_ = 1;
  vector<long long> dat;

  void init(int sz) {
    while (size_ <= sz) size_ *= 2;
    dat.resize(size_ * 2, 1LL << 60);
  }
  void update(int pos, long long x) {
    pos += size_;
    dat[pos] = x;
    while (pos /= 2) {
      dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
    }
  }
  long long query_(int l, int r, int a, int b, int u) {
    if (l <= a && b <= r) return dat[u];
    if (r <= a || b <= l) return 1LL << 60;
    int mid = (a + b) / 2;
    long long v1 = query_(l, r, a, mid, u * 2);
    long long v2 = query_(l, r, mid, b, u * 2 + 1);
    return min(v1, v2);
  }
  long long query(int l, int r) { return query_(l, r, 0, size_, 1); }
};