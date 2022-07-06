#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include <limits>
#include <queue>
#include <vector>
#include <algorithm>

#include "./graphTemplate.hpp"
using namespace std;

template <typename T = int>
struct ShortestPath {
  vector<T> dist;
  vector<int> from, id;
};

template <typename T>
ShortestPath<T> dikstra(const Graph<T> &g, int s) {
  ShortestPath<T> sp;
  const auto INF = numeric_limits<T>::max();
  sp.dist.resize(g.size(), INF);
  sp.dist[s] = 0;
  sp.from.resize(g.size(), -1);
  sp.id.resize(g.size(), -1);
  using Pi = pair<T, int>;
  priority_queue<Pi, vector<Pi>, greater<>> pq;
  pq.emplace(0, s);
  while (!pq.empty()) {
    auto [cost, idx] = pq.top();
    pq.pop();
    if (sp.dist[idx] < cost) continue;
    for (auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if (sp.dist[e.to] <= next_cost) continue;
      sp.dist[e.to] = next_cost;
      sp.from[e.to] = idx;
      sp.id[e.to] = e.idx;
      pq.emplace(sp.dist[e.to], e.to);
    }
  }
  return sp;
};
#endif