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
  vector<vector<int>> out_edge(n);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (v[i] < v[j]) {
        out_edge[i].push_back(j);
      }
    }
  }
  vector<int> dist(n, 0);
  vector<int> prev(n, -1);
  function<void(int)> dfs = [&](int cur) {
    for (int nxt : out_edge[cur]) {
      if (dist[cur] + 1 > dist[nxt]) {
        dist[nxt] = dist[cur] + 1;
        prev[nxt] = cur;
      }
      dfs(nxt);
    }
  };
  // worst case: O(n^3)
  for (int i = 0; i < n; ++i) {
    dfs(i);
  }
  // debug(dist);
  int index = max_element(dist.begin(), dist.end()) - dist.begin();
  cout << dist[index] + 1 << '\n';
  function<string(int)> build_lis = [&](int cur)->string {
    if (cur == -1) return "";
    return build_lis(prev[cur]) + to_string(v[cur]);
  };
  cout << build_lis(index) << '\n';
  return 0;
}