/*
 * author: cyclexit
 * start from: 2020-11-16 16:18
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
  int n, v;
  cin >> n >> v;
  vector<int> deno(n);
  for (int i = 0; i < n; ++i) {
    cin >> deno[i];
  }
  vector<int> dp(v + 1, - 1);
  vector<int> prev(v + 1, -1);
  for (int i = 0; i < n; ++i) {
    dp[deno[i]] = 1;
    prev[deno[i]] = 0;
  }
  for (int i = 1; i <= v; ++i) {
    if (dp[i] != -1) {
      for (int j = 0; j < n; ++j) {
        if (i + deno[j] > v) break;
        if (dp[i + deno[j]] == -1 || dp[i + deno[j]] > dp[i] + 1) {
          dp[i + deno[j]] = dp[i] + 1;
          prev[i + deno[j]] = i;
        }
      }
    }
  }
  if (dp[v] == -1) {
    cout << "NO" << '\n';
  } else {
    cout << dp[v] << '\n';
    int cur = v;
    while (cur != 0) {
      cout << cur - prev[cur] << ' ';
      cur = prev[cur];
    }
    cout << '\n';
  }
  return 0;
}