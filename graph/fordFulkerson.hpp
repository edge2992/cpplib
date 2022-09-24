#pragma once
#include <limits>
#include <vector>
using namespace std;

template <typename T>
struct FordFulkerson {
  struct Edge {
    int to;
    T cost;
    int rev;
  };

 public:
  int size_ = 0;
  vector<bool> used;
  vector<vector<Edge>> G;

  FordFulkerson(int size) : size_(size), used(size), G(size) {}

  void add_edge(int from, int to, T cap) {
    G[from].push_back({to, cap, (int)G[to].size()});
    G[to].push_back({from, 0, (int)G[from].size() - 1});
  }

  T max_flow(int s, int t) {
    T total_flow = 0;
    while (true) {
      fill(used.begin(), used.end(), false);
      T INF = numeric_limits<T>::max();
      T F = dfs(s, t, INF);
      if (F == 0) break;
      total_flow += F;
    }
    return total_flow;
  }

 private:
  T dfs(int pos, int goal, T F) {
    if (pos == goal) return F;
    used[pos] = true;
    for (int i = 0; i < (int)G[pos].size(); i++) {
      auto &e = G[pos][i];
      if (!used[e.to] && e.cost > 0) {
        T d = dfs(e.to, goal, min(F, e.cost));
        if (d > 0) {
          e.cost -= d;
          G[e.to][e.rev].cost += d;
          return d;
        }
      }
    }
    return 0;
  }
};