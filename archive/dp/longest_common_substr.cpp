/*
 * author: cyclexit
 * start from: 2020-11-16 17:32
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
  string s1, s2;
  cin >> s1 >> s2;
  int n = s1.size(), m = s2.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  int ans = 0, s1_start = -1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > ans) {
          ans = dp[i][j];
          s1_start = i - ans;
        }
      }
    }
  }
  cout << ans << '\n';
  if (ans != 0) {
    cout << s1.substr(s1_start, ans) << '\n';
  }
  return 0;
}