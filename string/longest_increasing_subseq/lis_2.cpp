/*
 * author: cyclexit
 * start from: 2020-12-14 17:29
 */
#include <bits/stdc++.h>

using namespace std;

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(const char* cstr) {
  return (string) cstr;
}

string to_string(string str) {
  return str;
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename T>
string to_string(const T& v) {
  string res = "[";
  bool first = true;
  for (const auto& x : v) {
    if (!first) res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "]";
  return res;
}

void debug() {cerr << endl;}

template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
  cerr << to_string(H) << " ";
  debug(T...);
}

class Graph {
 public:
  int n;
  vector<vector<int>> edge;
  // constructor
  Graph(int _n) : n(_n) {
    edge.resize(n);
  }
  // add an edge
  void add(int u, int v) {
    edge[u].push_back(v);
  }

  vector<int> topo;
  bool topo_sort() {
    topo.clear();
    vector<int> in_deg(n, 0);
    for (int i = 0; i < n; ++i) {
      for (int x : edge[i]) {
        ++in_deg[x];
      }
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (in_deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      topo.push_back(cur);
      for (int x : edge[cur]) {
        --in_deg[x];
        if (in_deg[x] == 0) {
          q.push(x);
        }
      }
    }
    return topo.size() == n;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  Graph g(n);
  vector<vector<int>> in_edge(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (v[i] < v[j]) {
        g.add(i, j);
        in_edge[j].push_back(i);
      }
    }
  }
  g.topo_sort();
  // debug(in_edge);
  vector<int> dist(n, 0);
  vector<int> prev(n, -1);
  // worst case: O(n^2)
  for (int i = 0; i < n; ++i) {
    for (int pre : in_edge[i]) {
      if (dist[pre] + 1 > dist[i]) {
        dist[i] = dist[pre] + 1;
        prev[i] = pre;
      }
    }
  }
  int index = max_element(dist.begin(), dist.end()) - dist.begin();
  cout << dist[index] + 1 << '\n';
  function<string(int)> build_lis = [&](int cur)->string {
    if (cur == -1) return "";
    return build_lis(prev[cur]) + to_string(v[cur]);
  };
  cout << build_lis(index) << '\n';
  return 0;
}