#pragma once
#include <algorithm>
#include <vector>

struct UnionFind {
  std::vector<int> data;
  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (data[a] < data[b]) std::swap(a, b);
    data[a] += data[b];
    data[b] = a;
    return true;
  }

  int find(int a) {
    if (data[a] < 0) return a;
    return data[a] = find(data[a]);
  }

  int same(int a, int b) { return find(a) == find(b); }

  int size(int k) { return -data[find(k)]; }

  std::vector<std::vector<int>> groups() {
    int n = (int)data.size();
    std::vector<std::vector<int>> ret(n);
    for (int i = 0; i < n; i++) {
      ret[find(i)].emplace_back(i);
    }
    ret.erase(std::remove_if(std::begin(ret), std::end(ret),
                        [&](const std::vector<int>& v) { return v.empty(); }),
              std::end(ret));
    return ret;
  }
};