/*
 * author: cyclexit
 * start from: 2020-11-11 20:27
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
  vector<int> price(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> price[i];
  }
  vector<int> dp(n + 1, 0);
  vector<int> cutted(n + 1, -1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (dp[i] < dp[j] + price[i - j]) {
        dp[i] = dp[j] + price[i - j];
        cutted[i] = i - j;
      }
    }
  }
  cout << dp[n] << '\n';
  function<void(int)> print_cut = [&](int len) {
    if (cutted[len] == len) {
      cout << len << '\n';
      return;
    }
    cout << cutted[len] << " ";
    print_cut(len - cutted[len]);
  };
  print_cut(n);
  return 0;
}